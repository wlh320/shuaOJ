lines = open("input").readlines()

grid = []
for line in lines:
    grid.append(line.strip())

n = len(grid)
m = len(grid[0])


def search(i0, j0, d):
    i, j = i0, j0
    di, dj = d

    pattern = ["X", "M", "A", "S"]
    for idx in range(4):
        if i < 0 or i >= n or j < 0 or j >= m:
            return 0
        if grid[i][j] != pattern[idx]:
            return 0
        i += di
        j += dj
    return 1


# 1
ans = 0
ds = ((-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (1, 1), (1, -1), (-1, 1))
for i in range(n):
    for j in range(m):
        if grid[i][j] != "X":
            continue
        for d in ds:
            ans += search(i, j, d)
print(ans)


# 2
def search2(i0, j0):
    i1, j1 = i0 + 2, j0 + 2
    if i1 < 0 or i1 >= n or j1 < 0 or j1 >= m:
        return 0

    if grid[i0][j0] + grid[i0 + 1][j0 + 1] + grid[i0 + 2][j0 + 2] not in ["MAS", "SAM"]:
        return 0
    if grid[i0][j0 + 2] + grid[i0 + 1][j0 + 1] + grid[i0 + 2][j0] not in ["MAS", "SAM"]:
        return 0

    return 1


ans = 0
for i in range(n):
    for j in range(m):
        ans += search2(i, j)


print(ans)
