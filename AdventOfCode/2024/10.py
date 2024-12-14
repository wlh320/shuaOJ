from collections import deque

lines = open("input").readlines()

grid = []
for line in lines:
    line = list(line.strip())
    line = list(map(int, line))
    grid.append(line)

n = len(grid)
m = len(grid[0])


def bfs(i, j):
    q = deque([(i, j)])
    s = set()

    res = 0
    while q:
        (i, j) = q.popleft()
        x = grid[i][j]
        if x == 9:
            res += 1
            s.add((i, j))
            continue

        for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ni, nj = i + di, j + dj
            if ni < 0 or ni >= n or nj < 0 or nj >= m:
                continue
            if grid[ni][nj] == x + 1:
                q.append((ni, nj))

    return len(s), res


ans1, ans2 = 0, 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 0:
            v1, v2 = bfs(i, j)
            ans1 += v1
            ans2 += v2
print(ans1)
print(ans2)
