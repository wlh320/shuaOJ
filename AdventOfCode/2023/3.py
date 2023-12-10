from collections import defaultdict
lines = open('input').readlines()
# lines = open('input1').readlines()

grid = []

for line in lines:
    line = line.strip()
    grid.append(line)


n, m = len(grid), len(grid[0])

# 1
ans = 0
gears = defaultdict(set)
number = 0
is_valid = False
for i in range(n):
    number = 0
    is_valid = False
    neighs = []
    for j in range(m):
        if grid[i][j].isdigit():
            number *= 10
            number += int(grid[i][j])
            # check around
            for di, dj in [(-1, 0), (1, 0), (0, 1), (0, -1), (-1, -1), (-1, 1), (1, -1), (1, 1)]:
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= n or nj < 0 or nj >= m:
                    continue
                if (not grid[ni][nj].isdigit()) and (not grid[ni][nj] == '.'):
                    is_valid = True
                    neighs.append((ni, nj))

            jj = j + 1
            if jj >= m or (not grid[i][jj].isdigit()):
                if is_valid:
                    ans += number
                    for nei in neighs:
                        neix, neiy = nei
                        if grid[neix][neiy] == '*':
                            gears[nei].add(number)
                number = 0
                is_valid = False
                neighs = []
print(ans)

# 2
ans = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == '*':
            nei = gears[(i, j)]
            if len(nei) == 2:
                l = list(nei)
                ans += l[0] * l[1]
print(ans)
