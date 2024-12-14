from collections import deque, defaultdict

lines = open("input").readlines()

grid = []

for line in lines:
    line = line.strip()
    grid.append(list(line))

n = len(grid)
m = len(grid[0])

vis = set()


def bfs(i, j):
    q = deque([(i, j)])
    groups = set()
    while q:
        (i, j) = q.popleft()
        groups.add((i, j))

        for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ni, nj = i + di, j + dj
            if ni < 0 or ni >= n or nj < 0 or nj >= m:
                continue
            if (ni, nj) in vis:
                continue
            if grid[ni][nj] == grid[i][j]:
                vis.add((ni, nj))
                q.append((ni, nj))
    return groups


g = defaultdict(list)

for i in range(n):
    for j in range(m):
        if (i, j) not in vis:
            s = bfs(i, j)
            if s:
                g[grid[i][j]].append(s)


def d(s):
    res = 0
    for i, j in s:
        for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ni, nj = i + di, j + dj
            if (ni, nj) not in s:
                res += 1
    return res


def side(s):
    ld = defaultdict(set)
    cd = defaultdict(set)
    for i, j in s:
        if (i - 1, j) not in s:
            ld[(-1, i - 1)].add(j)
        if (i + 1, j) not in s:
            ld[(1, i)].add(j)
        if (i, j - 1) not in s:
            cd[(-1, j - 1)].add(i)
        if (i, j + 1) not in s:
            cd[(1, j)].add(i)

    def calc(arrs):
        ans = 0
        for a in arrs:
            a = sorted(list(a))
            for i in range(len(a)):
                if i == 0 or (i > 0 and a[i] != a[i - 1] + 1):
                    ans += 1
        return ans

    return calc(ld.values()) + calc(cd.values())


# 1
ans = 0
for ss in g.values():
    for s in ss:
        ans += len(s) * d(s)
print(ans)


# 2
ans = 0
for ss in g.values():
    for s in ss:
        ans += len(s) * side(s)
print(ans)
