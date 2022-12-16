import re
from collections import defaultdict

# get input
data = open('input').read().splitlines()
PTN = re.compile(
    r'Sensor at x=(-?\d+), y=(-?\d+): closest beacon is at x=(-?\d+), y=(-?\d+)')
pnts = []
for line in data:
    sx, sy, bx, by = re.findall(PTN, line)[0]
    sx, sy, bx, by = int(sx), int(sy), int(bx), int(by)
    pnts.append((sx, sy, bx, by))

MIN = 0
MAX = 400_0000


def merge_intervals(intervals: list[tuple[int, int]]):
    """interval is like [a, b)"""
    intervals.sort(key=lambda x: x[0])
    ans = list()
    for itvl in intervals:
        if not ans:
            ans.append(itvl)
            continue
        if ans[-1][1] >= itvl[0]:
            ans[-1][1] = max(ans[-1][1], itvl[1])
        else:
            ans.append(itvl)
    return ans


def find_forbidden_intervals(y, part):
    intervals = set()
    for sx, sy, bx, by in pnts:
        dis = abs(sx - bx) + abs(sy - by)
        dis_y = abs(y - sy)
        dis_x = dis-dis_y
        if dis_x > 0:
            min_x = sx - dis_x if part == 1 else max(MIN, sx - dis_x)
            max_x = sx + dis_x if part == 1 else min(MAX + 1, sx + dis_x)
            intervals.add((min_x, max_x + 1))
    intervals = list(map(list, intervals))
    return intervals


# part1
Y = 200_0000
intervals = find_forbidden_intervals(Y, 1)
merged = merge_intervals(intervals)
count = sum([b - a for a, b in merged])
# exclude sensor&beacon
pnts_set = set()
for sx, sy, bx, by in pnts:
    pnts_set.add((sx, sy))
    pnts_set.add((bx, by))
for x, y in pnts_set:
    if y == Y:
        count -= 1
print(count)

# part2
for y in range(MAX + 1):
    intervals = find_forbidden_intervals(y, 2)
    # merge intevals
    merged = merge_intervals(intervals)
    # find target point
    if len(merged) == 2:
        print(merged[0][1] * MAX + y)
        break
