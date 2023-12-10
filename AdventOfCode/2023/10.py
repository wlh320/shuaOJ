from collections import deque

s = open("input").read().strip()
# s = open('input1').read().strip()

grid = []
lines = s.splitlines()
ans = 0
for line in lines:
    grid.append(list(line.strip()))

n = len(grid)
m = len(grid[0])

VALIDs = {
    (-1, 0): ["|", "7", "F"],
    (1, 0): ["|", "L", "J"],
    (0, -1): ["-", "L", "F"],
    (0, 1): ["-", "J", "7"],
}

DIRs = {
    "|": [(-1, 0), (1, 0)],
    "-": [(0, -1), (0, 1)],
    "7": [(1, 0), (0, -1)],
    "F": [(1, 0), (0, 1)],
    "L": [(-1, 0), (0, 1)],
    "J": [(-1, 0), (0, -1)],
    "S": [(-1, 0), (1, 0), (0, -1), (0, 1)],
}

start = None
for i in range(n):
    for j in range(m):
        if grid[i][j] == "S":
            start = (i, j)

# 1
ans = 0
q = deque()
assert start is not None
q.append((*start, 0))
vis = set([start])
while q:
    i, j, s = q.popleft()
    ans = max(ans, s)

    for di, dj in DIRs[grid[i][j]]:
        valids = VALIDs[(di, dj)]
        ni, nj = i + di, j + dj
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if (ni, nj) in vis:
            continue
        if grid[ni][nj] in valids:
            vis.add((ni, nj))
            q.append((ni, nj, s + 1))
print(ans)


# 2
ans = 0
loop = vis.copy()

for i in range(n):
    for j in range(m):
        if (i, j) not in loop:
            grid[i][j] = "."


# determine initial direction
i, j = start
first = []
for (di, dj), valids in VALIDs.items():
    ni, nj = i + di, j + dj
    if grid[ni][nj] in valids and (ni, nj) in loop:
        first.append(((ni, nj), (di, dj)))


def next_clock(char, fi, fj, di, dj):
    d_dict = {
        ("J", (1, 0)): 1,
        ("J", (0, 1)): -1,
        ("L", (1, 0)): -1,
        ("L", (0, -1)): 1,
        ("7", (0, 1)): 1,
        ("7", (-1, 0)): -1,
        ("F", (-1, 0)): 1,
        ("F", (0, -1)): -1,
    }
    t = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    d = d_dict.get((char, (di, dj)), 0)
    idx = t.index((fi, fj))
    # d == 1 -> clock, d == -1 -> reverse clock
    return t[(idx + d) % 4]


q1 = deque(
    [(first[0][0], first[1][1], first[0][1]), (first[1][0], first[0][1], first[1][1])]
)
vis1 = set([start, first[0][0], first[1][0]])
vis2 = set([])
while q1:
    (i, j), (fi, fj), (fdi, fdj) = q1.popleft()

    # find seed for searching
    si, sj = i + fi, j + fj
    if si >= 0 and si < n and sj >= 0 and sj < m and (si, sj) not in vis2:
        if (si, sj) not in loop:
            vis2.add((si, sj))

    (fi, fj) = next_clock(grid[i][j], fi, fj, fdi, fdj)

    si, sj = i + fi, j + fj
    if si >= 0 and si < n and sj >= 0 and sj < m and (si, sj) not in vis2:
        if (si, sj) not in loop:
            vis2.add((si, sj))

    for di, dj in DIRs[grid[i][j]]:
        valids = VALIDs[(di, dj)]
        ni, nj = i + di, j + dj
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if (ni, nj) in vis1:
            continue
        if grid[ni][nj] in valids:
            vis1.add((ni, nj))
            q1.append(((ni, nj), (fi, fj), (di, dj)))

# another BFS to find all
q2 = deque(vis2)
vis = set(q2)
while q2:
    (i, j) = q2.popleft()
    for di, dj in VALIDs.keys():
        ni, nj = i + di, j + dj
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if (ni, nj) in vis or (ni, nj) in loop:
            continue
        vis.add((ni, nj))
        q2.append((ni, nj))
print(len(vis))
