from copy import deepcopy

grid = open("input").read().splitlines()
grid[0] = grid[0].replace("S", "|")
grid = [list(line) for line in grid]


def move(grid, i):
    count = 0
    nc = len(grid[0])
    if i + 1 >= len(grid):
        return 0
    curr_line = grid[i]
    for j, ch in enumerate(curr_line):
        if ch != "|":
            continue
        if grid[i + 1][j] == "^":
            count += 1
            if 0 <= j - 1 < nc:
                grid[i + 1][j - 1] = "|"
            if 0 <= j + 1 < nc:
                grid[i + 1][j + 1] = "|"
        else:
            grid[i + 1][j] = "|"
    return count


# 1
ans = 0
grid1 = deepcopy(grid)
for i in range(len(grid1)):
    ans += move(grid1, i)
print(ans)


def solve2(grid):
    n = len(grid)
    m = len(grid[0])
    dp = [1 if x == "|" else 0 for x in grid[0]]
    for i in range(1, n):
        new_dp = dp.copy()
        for j in range(m):
            new_dp[j] = 0 if grid[i][j] == "^" else dp[j]
            if j - 1 > 0 and grid[i][j - 1] == "^":
                new_dp[j] += dp[j - 1]
            if j + 1 < m and grid[i][j + 1] == "^":
                new_dp[j] += dp[j + 1]
        dp = new_dp
    return sum(dp)


# 2
ans2 = solve2(grid)
print(ans2)
