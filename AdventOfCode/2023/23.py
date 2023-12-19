import sys
sys.setrecursionlimit(10000)
from collections import defaultdict

input = open("input").read().strip()
# input = open("input1").read().strip()

grid = []
lines = input.splitlines()
for line in lines:
    grid.append(list(line.strip()))

n, m = len(grid), len(grid[0])
start = (0, 1)
end = (n - 1, m - 2)

ans = 0
D = {"<": (0, -1), "v": (1, 0), ">": (0, 1), "^": (-1, 0)}


def dfs1(i, j, path, step):
    global ans

    if (i, j) == end:
        ans = max(ans, step)
        return

    for di, dj in D.values():
        if grid[i][j] in D and D[grid[i][j]] != (di, dj):
            continue
        ni, nj = i + di, j + dj
        if ni < 0 or nj < 0 or ni >= n or nj >= m:
            continue
        if grid[ni][nj] == "#":
            continue
        if (ni, nj) not in path:
            path.add((ni, nj))
            dfs1(ni, nj, path, step + 1)
            path.remove((ni, nj))


path = set([start])
dfs1(start[0], start[1], path, 0)
print(ans)

# 2
neighbors = defaultdict(dict)

for i in range(m):
    for j in range(n):
        if grid[i][j] == '#':
            continue
        for di, dj in D.values():
            ni, nj = i + di, j + dj
            if ni < 0 or nj < 0 or ni >= n or nj >= m:
                continue
            if grid[ni][nj] == "#":
                continue
            neighbors[(i, j)][(ni, nj)] = 1


while True:
    no_op = True
    for i in range(m):
        for j in range(n):
            if grid[i][j] == '#':
                continue
            # shorten path
            x = (i, j)
            if x not in neighbors:
                continue
            ns = neighbors[(i, j)]
            if len(ns) == 2:
                no_op = False
                n1, n2 = ns.keys()

                dis1 = neighbors[x][n1]
                dis2 = neighbors[x][n2]
                neighbors[n1][n2] = dis1 + dis2
                neighbors[n2][n1] = dis1 + dis2

                del neighbors[x]
                del neighbors[n1][x]
                del neighbors[n2][x]
                if not neighbors[n1]:
                    del neighbors[n1]
                if not neighbors[n2]:
                    del neighbors[n2]
    if no_op:
        break


ans = 0
def dfs2(x, path, step):
    global ans

    if x == end:
        ans = max(ans, step)
        return

    for nx in neighbors[x]:
        next_step = neighbors[x][nx]
        if nx not in path:
            path.add(nx)
            dfs2(nx, path, step + next_step)
            path.remove(nx)


path = set([start])
dfs2(start, path, 0)
print(ans)
