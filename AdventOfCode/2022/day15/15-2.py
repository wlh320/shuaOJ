import re
from collections import defaultdict
data = open('input').read().splitlines()
PTN = re.compile(
    r'Sensor at x=(-?\d+), y=(-?\d+): closest beacon is at x=(-?\d+), y=(-?\d+)')
pnts = []
for line in data:
    sx, sy, bx, by = re.findall(PTN, line)[0]
    sx, sy, bx, by = int(sx), int(sy), int(bx), int(by)
    pnts.append((sx, sy, bx, by))

forbid = defaultdict(set)

MIN = 0
MAX = 400_0000


def find_y(y):
    for sx, sy, bx, by in pnts:
        dis = abs(sx - bx) + abs(sy - by)
        dis_y = abs(y - sy)
        dis_x = dis-dis_y
        if dis_x > 0:
            min_x = max(MIN, sx - dis_x)
            max_x = min(MAX, sx + dis_x)
            forbid[y].add((min_x, max_x + 1))


def calc_y(y):
    find_y(y)
    intervals = list(map(list, forbid[y]))
    # merge intevals
    intervals.sort(key=lambda x: x[0])

    new_list = list()
    for itv in intervals:
        if not new_list:
            new_list.append(itv)
            continue
        if new_list[-1][1] >= itv[0]:
            new_list[-1][1] = max(new_list[-1][1], itv[1])
        else:
            new_list.append(itv)
    # find target point
    if len(new_list) == 2:
        print(new_list[0][1] * MAX + y)
        exit(0)


for y in range(MAX):
    calc_y(y)
