data = open('input').read().splitlines()
grid = [[int(x) for x in line] for line in data]
R, C = len(grid), len(grid[0])

# part1
seen = set([])
for i in range(R):
    for j in range(C):
        if i == 0:
            seen.add((i, j))
            mm = grid[i][j]
            for ii in range(1, R):
                if grid[ii][j] > mm:
                    seen.add((ii, j))
                mm = max(grid[ii][j], mm)
        elif i == R - 1:
            seen.add((i, j))
            mm = grid[i][j]
            for ii in reversed(range(0, R - 1)):
                if grid[ii][j] > mm:
                    seen.add((ii, j))
                mm = max(grid[ii][j], mm)
        elif j == 0:
            seen.add((i, j))
            mm = grid[i][j]
            for jj in range(1, C):
                if grid[i][jj] > mm:
                    seen.add((i, jj))
                mm = max(grid[i][jj], mm)
        elif j == C - 1:
            seen.add((i, j))
            mm = grid[i][j]
            for jj in reversed(range(0, C - 1)):
                if grid[i][jj] > mm:
                    seen.add((i, jj))
                mm = max(grid[i][jj], mm)
print(len(seen))

# part2
ans = 0
for i in range(R):
    for j in range(C):
        # to down
        d = 0
        block = False
        for ii in range(i + 1, R):
            if grid[ii][j] >= grid[i][j]:
                d = ii - i
                block = True
                break
        if not block:
            d = R - 1 - i

        # to up
        u = 0
        block = False
        mm = grid[i][j]
        for ii in reversed(range(0, i)):
            if grid[ii][j] >= grid[i][j]:
                u = i - ii
                block = True
                break
        if not block:
            u = i - 0

        # to right
        r = 0
        block = False
        mm = grid[i][j]
        for jj in range(j + 1, C):
            if grid[i][jj] >= grid[i][j]:
                r = jj - j
                block = True
                break
        if not block:
            r = C - 1 - j

        # to left
        l = 0
        block = False
        for jj in reversed(range(0, j)):
            if grid[i][jj] >= grid[i][j]:
                l = j - jj
                block = True
                break
        if not block:
            l = j - 0
        ans = max(ans, u * d * l * r)
print(ans)
