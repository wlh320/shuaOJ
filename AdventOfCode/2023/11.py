import bisect

s = open("input").read().strip()
# s = open("input1").read().strip()


lines = s.splitlines()
ans = 0
grid = []
for line in lines:
    line = list(line.strip())
    grid.append(line)
n, m = len(grid), len(grid[0])


def expand(grid):
    row_flag = [False] * n
    col_flag = [False] * m
    for i in range(n):
        for j in range(m):
            if grid[i][j] == "#":
                row_flag[i] = True
                col_flag[j] = True

    e_rows = [i for i in range(n) if not row_flag[i]]
    e_cols = [j for j in range(m) if not col_flag[j]]

    return e_rows, e_cols

    new_grid = []
    for i in range(n):
        line = []
        for j in range(m):
            if j in e_cols:
                line.append(grid[i][j])
                line.append(grid[i][j])
            else:
                line.append(grid[i][j])
        if i in e_rows:
            new_grid.append(line)
            new_grid.append(line)
        else:
            new_grid.append(line)

    assert len(new_grid) == n + len(e_rows)
    assert len(new_grid[0]) == m + len(e_cols)
    return new_grid


# 1
# galaxies = set()
# n, m = len(grid), len(grid[0])
# for i in range(n):
#     for j in range(m):
#         if grid[i][j] == '#':
#             galaxies.add((i, j))
#
# ans = 0
# galaxies = list(galaxies)
#
# for i in range(len(galaxies)):
#     i1, j1 = galaxies[i]
#     for j in range(i, len(galaxies)):
#         i2, j2 = galaxies[j]
#         ans += abs(i1 - i2) + abs(j1 - j2)
# print(ans)

# 2
ans = 0
e_rows, e_cols = expand(grid)
TIME = 1000000

galaxies = set()
n, m = len(grid), len(grid[0])
for i in range(n):
    for j in range(m):
        if grid[i][j] == "#":
            galaxies.add((i, j))

galaxies = list(galaxies)
for i in range(len(galaxies)):
    i1, j1 = galaxies[i]

    i1 += (TIME - 1) * bisect.bisect_left(e_rows, i1)
    j1 += (TIME - 1) * bisect.bisect_left(e_cols, j1)

    for j in range(i, len(galaxies)):
        i2, j2 = galaxies[j]

        i2 += (TIME - 1) * bisect.bisect_left(e_rows, i2)
        j2 += (TIME - 1) * bisect.bisect_left(e_cols, j2)

        ans += abs(i1 - i2) + abs(j1 - j2)

print(ans)
