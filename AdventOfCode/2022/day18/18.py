from collections import Counter
data = open('input').read().splitlines()
cubes = set()
for line in data:
    x, y, z = line.split(',')
    x, y, z = int(x), int(y), int(z)
    cubes.add((x, y, z))

s = dict()
for cube in cubes:
    x, y, z = cube
    s[(x, y, z)] = 6

    for dx, dy, dz in [(0, 0, 1), (0, 0, -1),
                       (0, 1, 0), (0, -1, 0),
                       (1, 0, 0), (-1, 0, 0)]:
        nx, ny, nz = x + dx, y + dy, z + dz
        if (nx, ny, nz) in cubes:
            s[(x, y, z)] -= 1

ans = sum([v for _, v in s.items()])
print(ans)

# part2


def find(parent, x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x


def union(parent, x, y):
    a = find(parent, x)
    b = find(parent, y)
    parent[a] = b


airs = set()
max_x, max_y, max_z = 0, 0, 0
for (x, y, z) in cubes:
    max_x = max(x, max_x)
    max_y = max(y, max_y)
    max_z = max(z, max_z)

for x in range(0, max_x + 2):
    for y in range(0, max_y + 2):
        for z in range(0, max_z + 2):
            if (x, y, z) not in cubes:
                airs.add((x, y, z))

parent = {x: x for x in airs}

for (x, y, z) in airs:
    for dx, dy, dz in [(0, 0, 1), (0, 0, -1),
                       (0, 1, 0), (0, -1, 0),
                       (1, 0, 0), (-1, 0, 0)]:
        nx, ny, nz = x + dx, y + dy, z + dz
        if (nx, ny, nz) in airs:
            union(parent, (x, y, z), (nx, ny, nz))

air_cubes = Counter([find(parent, (x, y, z)) for (x, y, z) in airs])
outside = air_cubes.most_common(1)[0][0]

for (x, y, z) in airs:
    rmv = 0
    if find(parent, (x, y, z)) != outside:
        for dx, dy, dz in [(0, 0, 1), (0, 0, -1),
                           (0, 1, 0), (0, -1, 0),
                           (1, 0, 0), (-1, 0, 0)]:
            nx, ny, nz = x + dx, y + dy, z + dz
            if (nx, ny, nz) in cubes:
                rmv += 1
        ans -= rmv
print(ans)
