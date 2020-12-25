from copy import deepcopy
lines = open('input').readlines()
lines = list(map(lambda x: x.strip(), lines))
minx, miny, minz = 10000, 10000, -1
maxx, maxy, maxz = -1000, -1000, 1
alives = set()
def count(old_alives, x, y, z):
    global minx, miny, minz, maxx, maxy, maxz
    cnt = 0
    dxs, dys ,dzs = [-1, 0, 1], [-1, 0, 1], [-1, 0, 1]
    for dx in dxs:
        for dy in dys:
            for dz in dzs:
                newx, newy, newz = x+dx, y+dy, z+dz
                if dx == 0 and dy == 0 and dz == 0:
                    continue
                minx, miny, minz = min(minx, newx), min(miny, newy), min(minz, newz)
                maxx, maxy, maxz = max(maxx, newx), max(maxy, newy), max(maxz, newz)
                if (newx, newy, newz) in old_alives:
                    cnt += 1
    return cnt

for newx, line in enumerate(lines):
    for newy, point in enumerate(line):
        if point == '#':
            alives.add((newx, newy, 0))
        minx, miny, minz = min(minx, newx), min(miny, newy), min(minz, 0)
        maxx, maxy, maxz = max(maxx, newx), max(maxy, newy), max(maxz, 0)


for epoch in range(6):
    old_alives = deepcopy(alives)
    alives = set()
    cx, cy, cz = minx - 1, miny - 1, minz - 1
    cmx, cmy, cmz = maxx + 1, maxy + 1, maxz + 1
    for x in range(cx, cmx+1):
        for y in range(cy, cmy+1):
            for z in range(cz, cmz+1):
                cnt = count(old_alives, x, y, z)
                if (x,y,z) in old_alives:
                    if cnt == 2 or cnt == 3:
                        alives.add((x, y, z))
                elif (x,y,z) not in old_alives and cnt == 3:
                    alives.add((x, y, z))
print(len(alives))
