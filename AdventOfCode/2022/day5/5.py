import re

# [T] [V]                     [W]
# [V] [C] [P] [D]             [B]
# [J] [P] [R] [N] [B]         [Z]
# [W] [Q] [D] [M] [T]     [L] [T]
# [N] [J] [H] [B] [P] [T] [P] [L]
# [R] [D] [F] [P] [R] [P] [R] [S] [G]
# [M] [W] [J] [R] [V] [B] [J] [C] [S]
# [S] [B] [B] [F] [H] [C] [B] [N] [L]
#  1   2   3   4   5   6   7   8   9

S = [
    'TVJWNRMS', 'VCPQJDWB', 'PRDHFJB',
    'DNMBPRF', 'BTPRVH', 'TPBC',
    'LPRJB', 'WBZTLSCN', 'GSL'
]
# stacks = ['NZ', 'DCM', 'P']
data = open('input').readlines()

# part1
stacks = list(map(list, S))
stacks = [x[::-1] for x in stacks]
for line in data:
    line = line.strip()
    n, s, t = re.findall(r'move (\d+) from (\d+) to (\d+)', line)[0]
    n, s, t = int(n), int(s), int(t)
    for i in range(n):
        v = stacks[s - 1].pop()
        stacks[t - 1].append(v)

ans = ''.join([x[-1] for x in stacks])
print(ans)

# part2
stacks = list(map(list, S))
# stacks = [x[::-1] for x in stacks]
for line in data:
    line = line.strip()
    n, s, t = re.findall(r'move (\d+) from (\d+) to (\d+)', line)[0]
    n, s, t = int(n), int(s), int(t)
    tmp = stacks[s-1][0:n]
    stacks[s-1] = stacks[s-1][n:]
    tmp.extend(stacks[t-1])
    stacks[t-1] = tmp

ans = ''.join([x[0] for x in stacks])
print(ans)
