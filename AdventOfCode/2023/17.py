from functools import cache
from collections import deque
input = open("input").read().strip()
# input = open("input1").read().strip()

lines = input.splitlines()

grid = []
for line in lines:
    line = list(map(int, list(line)))
    grid.append(line)

n, m = len(grid), len(grid[0])

DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]


q = deque()
q.append((0, 0, -1, 0, 0))
cache = dict()
while q:
    i, j, d, cnt, curr = q.popleft()
    # print(i, j, d, cnt, curr)
    if cnt > 10:
        continue
    if (i, j, d, cnt) in cache and curr >= cache[(i, j, d, cnt)]:
        continue
    else:
        cache[(i, j, d, cnt)] = curr

    for dir in range(len(DIRS)):
        di, dj = DIRS[dir]
        ni, nj = i + di, j + dj
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if (dir + 2) % 4 == d:
            continue
        if dir == d:
            q.append((ni, nj, dir, cnt + 1, curr + grid[ni][nj]))
        else:
            if d == -1 or cnt >= 4:
                q.append((ni, nj, dir, 1, curr + grid[ni][nj]))


ans = 10**10
for k, v in cache.items():
    i, j, d, cnt = k
    if i == n - 1 and j == m - 1 and cnt >= 4:
        ans = min(ans, v)
# super slow
print(ans)
