import re
from collections import defaultdict
data = open('input').read().splitlines()
forbid = defaultdict(set)
ans = set()
Y = 200_0000
# Y = 10
PTN = re.compile(
    r'Sensor at x=(-?\d+), y=(-?\d+): closest beacon is at x=(-?\d+), y=(-?\d+)')
for line in data:
    sx, sy, bx, by = re.findall(PTN, line)[0]
    sx, sy, bx, by = int(sx), int(sy), int(bx), int(by)
    print(sx, sy, bx, by)
    dis = abs(sx - bx) + abs(sy - by)

    dis_y = abs(Y - sy)
    for dis_x in range(0, dis-dis_y + 1):
        if not (by == Y and sx - dis_x == bx):
            ans.add(sx - dis_x)
        if not (by == Y and sx + dis_x == bx):
            ans.add(sx + dis_x)
print(len(ans))
