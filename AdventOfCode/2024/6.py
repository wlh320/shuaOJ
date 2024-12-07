lines = open("input").readlines()

grid = []
for line in lines:
    line = line.strip()
    grid.append(list(line))

n = len(grid)
m = len(grid[0])

i0 = 0
j0 = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == "^":
            i0, j0 = i, j
i, j = i0, j0
D = [(-1, 0), (0, 1), (1, 0), (0, -1)]

# 1
d = 0
visited = set()
while True:
    visited.add((i, j))
    ni, nj = i + D[d][0], j + D[d][1]
    if ni < 0 or ni >= n or nj < 0 or nj >= m:
        break

    if grid[ni][nj] == "#":
        d = (d + 1) % 4
        continue
    i, j = ni, nj
print(len(visited))


# 2
def try_walk():
    i, j = i0, j0
    D = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    d = 0
    visited = set()

    while True:
        # trapped in loop
        if (i, j, d) in visited:
            return True
        visited.add((i, j, d))
        ni, nj = i + D[d][0], j + D[d][1]
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            break

        if grid[ni][nj] == "#":
            d = (d + 1) % 4
            continue
        i, j = ni, nj
    return False


ans = 0
for ii, jj in visited:
    if ii == i0 and jj == j0:
        continue

    grid[ii][jj] = "#"
    ans += try_walk()
    grid[ii][jj] = "."

print(ans)
