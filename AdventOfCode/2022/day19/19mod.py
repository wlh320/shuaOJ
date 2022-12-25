import re
data = open('input').read().splitlines()
T = 24
ORE = 0
CLY = 1
OBS = 2
GEO = 3


memo = {}


def dfs(t, bp, robots, mines):
    global res, memo, memo_t
    h = (t, *robots, *mines)
    if h in memo:
        return memo[h]

    # collect
    old_mines = mines[:]
    for robot in [ORE, CLY, OBS, GEO]:
        mines[robot] += robots[robot]
    memo[h] = mines[GEO]

    # time limit
    if t == T:
        res = max(mines[GEO], res)
        return

    # prune
    if mines[GEO] + (T - t) * (2 * robots[GEO] + (T - t)) // 2 < res:
        return
    if robots[ORE] > max(bp[CLY], bp[OBS][0], bp[GEO][0]):
        return
    if robots[CLY] > bp[OBS][1] or robots[OBS] > bp[GEO][1]:
        return

    # build
    if old_mines[ORE] >= bp[GEO][0] and old_mines[OBS] >= bp[GEO][1]:
        new_robots, new_mines = robots[:], mines[:]
        new_mines[ORE] -= bp[GEO][0]
        new_mines[OBS] -= bp[GEO][1]
        new_robots[GEO] += 1
        dfs(t + 1, bp, new_robots, new_mines)
        return  # prune, too
    if old_mines[ORE] >= bp[ORE]:
        new_robots, new_mines = robots[:], mines[:]
        new_mines[ORE] -= bp[ORE]
        new_robots[ORE] += 1
        dfs(t + 1, bp, new_robots, new_mines)
    if old_mines[ORE] >= bp[CLY]:
        new_robots, new_mines = robots[:], mines[:]
        new_mines[ORE] -= bp[CLY]
        new_robots[CLY] += 1
        dfs(t + 1, bp, new_robots, new_mines)
    if old_mines[ORE] >= bp[OBS][0] and old_mines[CLY] >= bp[OBS][1]:
        new_robots, new_mines = robots[:], mines[:]
        new_mines[ORE] -= bp[OBS][0]
        new_mines[CLY] -= bp[OBS][1]
        new_robots[OBS] += 1
        dfs(t + 1, bp, new_robots, new_mines)
    # do not build
    dfs(t + 1, bp, robots[:], mines[:])


# parse input
bps = []
PTN = re.compile(r'(\d+)')
for i, line in enumerate(data):
    words = line.split(' costs ')
    xs = list(map(lambda x: x.split('.')[0], words[1:]))
    blueprint = []
    xs = list(map(lambda x: re.findall(PTN, x), xs))
    for target, cost in zip([ORE, CLY, OBS, GEO], xs):
        # ore, ore, ore and clay, ore and obsidian
        cost = list(map(int, cost))
        if len(cost) == 1:
            blueprint.append(cost[0])
        else:
            blueprint.append(cost)
    bps.append(blueprint)

# part1
ans = 0
for i, bp in enumerate(bps):
    memo = {}
    res = 0
    dfs(1, bp, [1, 0, 0, 0], [0, 0, 0, 0])
    ans += res * (i + 1)
print(ans)

# part2
T = 32
ans = 1
for bp in bps[:3]:
    memo = {}
    res = 0
    dfs(1, bp, [1, 0, 0, 0], [0, 0, 0, 0])
    ans *= res
print(ans)
