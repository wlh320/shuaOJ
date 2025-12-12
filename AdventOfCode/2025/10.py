from collections import deque
from z3 import *

lines = open('input').read().splitlines()

def parse(line: str):
    s1 = line[1: line.find('(') - 2]
    s2 = line[line.find('('): line.find('{') - 1]
    s3 = line[line.find('{') + 1:-1]
    target = tuple(i for i in range(len(s1)) if s1[i] == '#')
    actions = list(tuple(map(int, x[1:-1].split(','))) for x in s2.split(' '))
    values = tuple(map(int, s3.split(',')))
    return target, actions, values

def solve(target, actions):
    def merge(xs, action):
        s1 = set(xs)
        for v in action:
            if v in s1:
                s1.remove(v)
            else:
                s1.add(v)
        return tuple(sorted(list(s1)))

    start = tuple()
    vis = set()
    q = deque([(0, start)])
    while q:
        i, xs = q.popleft()
        if xs == target:
            return i
        if xs in vis:
            continue
        vis.add(xs)
        for action in actions:
            next = merge(xs, action)
            q.append((i + 1, next))
    return 0

def solve2(target, actions):
    n = len(target)
    vars = [Int(f'x{i}') for i in range(len(actions))]
    opt = Optimize()
    for i in range(len(actions)):
        opt.add(vars[i] >= 0)
    for i in range(n):
        vals = [vars[j] for j, action in enumerate(actions) if i in action]
        opt.add(sum(vals) == target[i])
    obj = sum(vars)
    opt.minimize(obj)
    if opt.check() == sat:
        m = opt.model()
        return m.eval(obj).as_long()
    assert False # must be solvable

ans1 = 0
ans2 = 0
for line in lines:
    target, actions, values = parse(line)
    # 1. just DFS
    ans1 += solve(target, actions)
    # 2. solve ILP
    ans2 += solve2(values, actions)
print(ans1)
print(ans2)
