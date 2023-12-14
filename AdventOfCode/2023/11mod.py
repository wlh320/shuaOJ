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


def find_empties(grid):
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


def find_galaxies(grid):
    galaxies = set()
    n, m = len(grid), len(grid[0])
    for i in range(n):
        for j in range(m):
            if grid[i][j] == "#":
                galaxies.add((i, j))
    galaxies = list(galaxies)
    return galaxies


def compute_distance(grid, T):
    galaxies = find_galaxies(grid)
    e_rows, e_cols = find_empties(grid)
    ans = 0
    for i in range(len(galaxies)):
        i1, j1 = galaxies[i]
        i1 += (T - 1) * bisect.bisect_left(e_rows, i1)
        j1 += (T - 1) * bisect.bisect_left(e_cols, j1)

        for j in range(i, len(galaxies)):
            i2, j2 = galaxies[j]
            i2 += (T - 1) * bisect.bisect_left(e_rows, i2)
            j2 += (T - 1) * bisect.bisect_left(e_cols, j2)

            ans += abs(i1 - i2) + abs(j1 - j2)
    return ans


# 1
ans = compute_distance(grid, T=2)
print(ans)
# 2
ans = compute_distance(grid, T=100_0000)
print(ans)
