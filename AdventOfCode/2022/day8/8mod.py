data = open('input').read().splitlines()
grid = [[int(x) for x in line] for line in data]
R, C = len(grid), len(grid[0])


# part1
seen = set([])


def scan1(i, j, dim, rg):
    mm = grid[i][j]
    for idx in rg:
        tree = grid[idx][j] if dim == 0 else grid[i][idx]
        if tree > mm:
            seen.add((idx, j) if dim == 0 else (i, idx))
        mm = max(tree, mm)


ans = 0
for i in range(R):
    for j in range(C):
        if i == 0:
            seen.add((i, j))
            scan1(i, j, 0, range(1, R))
        elif i == R - 1:
            seen.add((i, j))
            scan1(i, j, 0, reversed(range(0, R - 1)))
        elif j == 0:
            seen.add((i, j))
            scan1(i, j, 1, range(1, C))
        elif j == C - 1:
            seen.add((i, j))
            scan1(i, j, 1, reversed(range(0, C - 1)))
print(len(seen))


def scan2(i, j, dim, rg):
    block = False
    v = 0
    last_idx = 0
    for idx in rg:
        last_idx = idx
        tree = grid[idx][j] if dim == 0 else grid[i][idx]
        if tree >= grid[i][j]:
            block = True
            v = abs(idx - i) if dim == 0 else abs(idx - j)
            break
    if not block:
        v = abs(last_idx - i) if dim == 0 else abs(last_idx - j)
    return v


# part2
ans = 0
for i in range(R):
    for j in range(C):
        d = scan2(i, j, 0, range(i + 1, R))
        u = scan2(i, j, 0, reversed(range(0, i)))
        r = scan2(i, j, 1, range(j + 1, C))
        l = scan2(i, j, 1, reversed(range(0, j)))
        ans = max(ans, u * d * l * r)
print(ans)
