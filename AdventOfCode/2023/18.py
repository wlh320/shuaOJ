input = open("input").read().strip()
# input = open("input1").read().strip()

lines = input.splitlines()

max_n, max_m = 0, 0
min_n, min_m = 10**9, 10**9

D = {"U": (-1, 0), "D": (1, 0), "L": (0, -1), "R": (0, 1)}

ans = 0
i, j = 0, 0
for line in lines:
    d, l, c = line.split()
    l = int(l)
    for _ in range(l):
        i, j = i + D[d][0], j + D[d][1]
        max_n = max(i, max_n)
        min_n = min(i, min_n)
        max_m = max(j, max_m)
        min_m = min(j, min_m)

off_n, off_m = -min_n, -min_m
n, m = max_n + off_n + 1, max_m + off_m + 1
grid = [["." for _ in range(m)] for _ in range(n)]

i, j = off_n, off_m
for line in lines:
    d, l, c = line.split()
    l = int(l)

    for _ in range(l):
        grid[i][j] = "#"
        i, j = i + D[d][0], j + D[d][1]

cands = []
for j in range(m):
    if grid[0][j] == "#":
        cands.append(j)

start = (1, cands[2])

vis = set()
from collections import deque

q = deque([start])
while q:
    i, j = q.popleft()
    for di, dj in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
        ni, nj = i + di, j + dj
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if grid[ni][nj] == "#":
            continue
        grid[ni][nj] = "#"
        q.append((ni, nj))

cnt = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == "#":
            cnt += 1
print(cnt)

INS = {0: (0, 1), 1: (1, 0), 2: (0, -1), 3: (-1, 0)}


# 2 不会，现学别人的
def det(a, b):
    xa, ya = a
    xb, yb = b
    return xa * yb - ya * xb


def area(points):
    # Shoelace's fomula
    tot = 0
    points.append(points[0])
    for p1, p2 in zip(points, points[1:]):
        tot += det(p1, p2)
    return tot // 2


min_n, max_n = 10**10, 0
min_m, max_m = 10**10, 0

points = []
i, j = 0, 0
p = 0
for line in lines:
    d, l, c = line.split()
    c = c[2:-1]
    c, d = int(c[:5], 16), int(c[5:], 16)

    i, j = i + INS[d][0] * c, j + INS[d][1] * c
    points.append((i, j))
    p += c

p = p // 2 + 1
ans = abs(area(points) - p)
print(ans)
