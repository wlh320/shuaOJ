from collections import deque

input = open("input").read().strip()
# input = open("input1").read().strip()
grid = []

lines = input.splitlines()
for line in lines:
    grid.append(list(line.strip()))

n, m = len(grid), len(grid[0])

start = None
for i in range(n):
    for j in range(m):
        if grid[i][j] == "S":
            start = (i, j)
            grid[i][j] = "."


q = deque([(start[0], start[1], 0)])
vis = set()
ans = set()
N = 64

while q:
    i, j, s = q.popleft()
    if s > N:
        continue
    if s == N:
        ans.add((i, j))
    for di, dj in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
        ni, nj = i + di, j + dj
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if (ni, nj, s) in vis:
            continue
        if grid[ni][nj] == "#":
            continue
        vis.add((ni, nj, s))
        q.append((ni, nj, s + 1))

print(len(ans))

# 2
# TODO
