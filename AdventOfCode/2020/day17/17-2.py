from copy import deepcopy
lines = open('input').readlines()
lines = list(map(lambda x: x.strip(), lines))
minx, miny, minz, minw = 10000, 10000, -1, -1
maxx, maxy, maxz, maxw = -1000, -1000, 1, 1 
alives = set()
def count(old_alives, x, y, z, w):
    global minx, miny, minz, maxx, maxy, maxz, minw, maxw
    cnt = 0
    dxs, dys ,dzs, dws = [-1, 0, 1], [-1, 0, 1], [-1, 0, 1], [-1, 0, 1]
    for dx in dxs:
        for dy in dys:
            for dz in dzs:
                for dw in dws:
                    newx, newy, newz, neww = x+dx, y+dy, z+dz, w+dw
                    if dx == 0 and dy == 0 and dz == 0 and dw == 0:
                        continue
                    minx, miny, minz = min(minx, newx), min(miny, newy), min(minz, newz)
                    minw = min(minw, neww)
                    maxx, maxy, maxz = max(maxx, newx), max(maxy, newy), max(maxz, newz)
                    maxw = max(maxw, neww)
                    if (newx, newy, newz, neww) in old_alives:
                        cnt += 1
    return cnt

for newx, line in enumerate(lines):
    for newy, point in enumerate(line):
        if point == '#':
            alives.add((newx, newy, 0, 0))
        minx, miny, minz = min(minx, newx), min(miny, newy), min(minz, 0)
        maxx, maxy, maxz = max(maxx, newx), max(maxy, newy), max(maxz, 0)
        minw = min(minw, 0)
        maxw = max(maxw, 0)


for epoch in range(6):
    old_alives = deepcopy(alives)
    alives = set()
    cx, cy, cz = minx - 1, miny - 1, minz - 1
    cw = minw - 1
    cmx, cmy, cmz = maxx + 1, maxy + 1, maxz + 1
    cmw = maxw + 1
    for x in range(cx, cmx+1):
        for y in range(cy, cmy+1):
            for z in range(cz, cmz+1):
                for w in range(cw, cmw+1):
                    cnt = count(old_alives, x, y, z, w)
                    if (x,y,z, w) in old_alives:
                        if cnt == 2 or cnt == 3:
                            alives.add((x, y, z, w))
                    elif (x,y,z, w) not in old_alives and cnt == 3:
                        alives.add((x, y, z, w))
print(len(alives))