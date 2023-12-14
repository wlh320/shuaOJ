from collections import deque

input = open("input").read().strip()
# input = open("input1").read().strip()

grid = input.splitlines()
n, m = len(grid), len(grid[0])


# 1
def run(si, sj, sd):
    vis = set([])
    q = deque([])
    q.append((si, sj, sd))
    while q:
        i, j, dir = q.popleft()
        di, dj = dir

        ni, nj = i + di, j + dj
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if (ni, nj, dir) in vis:
            continue
        vis.add((ni, nj, dir))
        if grid[ni][nj] == ".":
            q.append((ni, nj, dir))
        elif grid[ni][nj] == "/":
            if dir == (0, 1):
                dir = (-1, 0)
            elif dir == (0, -1):
                dir = (1, 0)
            elif dir == (1, 0):
                dir = (0, -1)
            elif dir == (-1, 0):
                dir = (0, 1)
            q.append((ni, nj, dir))
        elif grid[ni][nj] == "\\":
            if dir == (0, 1):
                dir = (1, 0)
            elif dir == (0, -1):
                dir = (-1, 0)
            elif dir == (1, 0):
                dir = (0, 1)
            elif dir == (-1, 0):
                dir = (0, -1)
            q.append((ni, nj, dir))
        elif grid[ni][nj] == "-":
            if dir == (0, 1) or dir == (0, -1):
                q.append((ni, nj, dir))
            else:
                q.append((ni, nj, (0, 1)))
                q.append((ni, nj, (0, -1)))
        elif grid[ni][nj] == "|":
            if dir == (1, 0) or dir == (-1, 0):
                q.append((ni, nj, dir))
            else:
                q.append((ni, nj, (1, 0)))
                q.append((ni, nj, (-1, 0)))

    ans = set()
    for i, j, dir in vis:
        ans.add((i, j))

    return len(ans)


# 1
si, sj, sd = 0, -1, (0, 1)
ans = run(si, sj, sd)
print(ans)


# 2
ans = 0
for j in range(m):
    r1 = run(-1, j, (1, 0))
    ans = max(ans, r1)
    r2 = run(n, j, (-1, 0))
    ans = max(ans, r2)

for i in range(n):
    r1 = run(i, -1, (0, 1))
    ans = max(ans, r1)
    r2 = run(i, 0, (0, -1))
    ans = max(ans, r2)
print(ans)
