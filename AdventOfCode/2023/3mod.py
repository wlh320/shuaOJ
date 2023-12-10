from collections import defaultdict

lines = open('input').readlines()
grid = []
for line in lines:
    line = line.strip()
    grid.append(line)
n, m = len(grid), len(grid[0])

is_digit = lambda i, j: grid[i][j].isdigit()
is_empty = lambda i, j: grid[i][j] == '.'
is_symbol = lambda i, j: not is_digit(i, j) and not is_empty(i, j)
is_gear = lambda i, j: grid[i][j] == '*'

def search_neighbors(i, j):
    neighs = set()
    for di, dj in [(-1, 0), (1, 0), (0, 1), (0, -1), (-1, -1), (-1, 1), (1, -1), (1, 1)]:
        ni, nj = i + di, j + dj
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if is_symbol(ni, nj):
            neighs.add((ni, nj))
    return neighs

# 1
ans = 0
gears = defaultdict(list)
for i in range(n):
    number, neighs = 0, set()
    for j in range(m):
        if not is_digit(i, j):
            continue
        number = number * 10 + int(grid[i][j])
        neighs |= search_neighbors(i, j)
        # find an end of number
        if j + 1 >= m or not is_digit(i, j + 1):
            if neighs:
                ans += number
                for x, y in neighs:
                    if is_gear(x, y):
                        gears[(x, y)].append(number)
            number, neighs = 0, set()
print(ans)

# 2
ans = 0
for _, numbers in gears.items():
    if len(numbers) == 2:
        ans += numbers[0] * numbers[1]
print(ans)
