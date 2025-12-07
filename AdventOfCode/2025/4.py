data = open("input").read()
grid = [list(line) for line in data.splitlines()]


def solve(grid):
    def count(i, j):
        cnt = 0
        for di in (-1, 0, 1):
            for dj in (-1, 0, 1):
                ni, nj = i + di, j + dj
                if (di, dj) == (0, 0) or ni < 0 or ni >= n or nj < 0 or nj >= m:
                    continue
                if grid[ni][nj] == "@":
                    cnt += 1
        return cnt

    n, m = len(grid), len(grid[0])
    accessed = set()
    for i in range(n):
        for j in range(m):
            if grid[i][j] != "@":
                continue
            if count(i, j) < 4:
                accessed.add((i, j))
    return accessed


ans1 = len(solve(grid))
print(ans1)

ans2 = 0
while True:
    accessed = solve(grid)
    ans2 += len(accessed)
    if not accessed:
        break
    for i, j in accessed:
        grid[i][j] = "X"
print(ans2)
