import re
from collections import defaultdict
from copy import deepcopy
data = open('input').read().splitlines()
PTN = r'(\d+)'
T = 24


def can_build(mines, blueprint):
    # print(f'can {mines.items()}, {blueprint.items()}')
    num_ore = mines['ore'] // blueprint['ore']
    num_clay = mines['ore'] // blueprint['clay']
    num_obs = min(mines['ore'] // blueprint['obs'][0],
                  mines['clay'] // blueprint['obs'][1])
    num_geo = min(mines['ore'] // blueprint['geo'][0],
                  mines['obs'] // blueprint['geo'][1])
    return num_ore, num_clay, num_obs, num_geo


def is_enough(mines, needed):
    # print(mines.items(), needed.items())
    for k in needed.keys():
        if mines[k] < needed[k]:
            return False
    return True


def build(robots, mines, nums, blueprint):
    n1, n2, n3, n4 = nums
    new_robots, new_mines = deepcopy(robots), deepcopy(mines)
    new_mines['ore'] -= n1 * blueprint['ore'] + n2 * blueprint['clay'] + \
        n3 * blueprint['obs'][0] + n4 * blueprint['geo'][0]
    new_mines['clay'] -= n3 * blueprint['obs'][1]
    new_mines['obs'] -= n4 * blueprint['geo'][1]
    new_mines['geo'] -= 0

    new_robots['ore'] += n1
    new_robots['clay'] += n2
    new_robots['obs'] += n3
    new_robots['geo'] += n4
    return new_robots, new_mines


def hash(t, robots, mines):
    l = [str(t)]
    for r in robots.values():
        l.append(str(r))
    for m in mines.values():
        l.append(str(m))
    return ','.join(l)


memo = {}


def dfs(t, robots, mines, blueprint):
    global res
    h = hash(t, robots, mines)
    if h in memo:
        return memo[h]
    old_mines = deepcopy(mines)
    # collect
    for robot in robots:
        mines[robot] += robots[robot]
    memo[h] = mines['geo']

    # prune
    if mines['geo'] + (T - t) * (2 * robots['geo'] + (T - t)) // 2 < res:
        return
    if robots['ore'] > 4:
        return

    if t == T:
        # print(robots.items(), mines.items())
        res = max(mines['geo'], res)
        return
    # build
    for (n1, n2, n3, n4) in [(0, 0, 0, 1), (0, 0, 1, 0), (0, 1, 0, 0), (1, 0, 0, 0), (0, 0, 0, 0)]:
        needed = {}
        needed['ore'] = n1 * blueprint['ore'] + n2 * blueprint['clay'] + \
            n3 * blueprint['obs'][0] + n4 * blueprint['geo'][0]
        needed['clay'] = n3 * blueprint['obs'][1]
        needed['obs'] = n4 * blueprint['geo'][1]
        if is_enough(old_mines, needed):
            needed['geo'] = 0
            new_robots, new_mines = build(
                robots, mines, [n1, n2, n3, n4], blueprint)
            dfs(t + 1, new_robots, new_mines, blueprint)
            if (n1, n2, n3, n4) == (0, 0, 0, 1):
                break


ans = 0
for i, line in enumerate(data):
    words = line.split(' costs ')
    xs = list(map(lambda x: x.split('.')[0], words[1:]))
    blueprint = {}
    xs = list(map(lambda x: re.findall(PTN, x), xs))
    for target, cost in zip(['ore', 'clay', 'obs', 'geo'], xs):
        # ore, ore, ore and clay, ore and obsidian
        cost = list(map(int, cost))
        if len(cost) == 1:
            blueprint[target] = cost[0]
        else:
            blueprint[target] = cost
    print(blueprint)

    robots = defaultdict(int)
    robots['ore'] = 1
    memo = {}
    res = 0
    dfs(1, robots, defaultdict(int), blueprint)
    print(res)
    ans += ans * (i + 1)
print(ans)

# part2
T = 32
ans = 1
for line in data[:3]:
    words = line.split(' costs ')
    xs = list(map(lambda x: x.split('.')[0], words[1:]))
    blueprint = {}
    xs = list(map(lambda x: re.findall(PTN, x), xs))
    for target, cost in zip(['ore', 'clay', 'obs', 'geo'], xs):
        # ore, ore, ore and clay, ore and obsidian
        cost = list(map(int, cost))
        if len(cost) == 1:
            blueprint[target] = cost[0]
        else:
            blueprint[target] = cost
    print(blueprint)

    robots = defaultdict(int)
    robots['ore'] = 1
    memo = {}
    res = 0
    dfs(1, robots, defaultdict(int), blueprint)
    ans *= res
print(ans)
