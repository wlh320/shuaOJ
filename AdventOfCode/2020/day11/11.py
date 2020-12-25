from copy import deepcopy
lines = open('input').readlines()

def count_func(grid, i, j, part1=True):
    dis = [-1, 0, 1]
    djs = [-1, 0, 1]
    count = 0
    for di in dis:
        for dj in djs:
            if di == 0 and dj == 0:
                continue
            newi = i + di
            newj = j + dj
            while 0 <= newi < len(grid) and 0 <= newj < len(grid[newi]):
                if grid[newi][newj] == '#':
                    count += 1
                    break
                if part1:
                    break
                if grid[newi][newj] == 'L':
                    break
                newi += di
                newj += dj
    return count

def count_occupied(grid):
    count = 0
    for line in grid:
        for x in line:
            if x == '#':
                count += 1
    return count

def play(part1=True):
    curr_grid = list(map(lambda x: list(x.strip()), lines))
    last_grid = deepcopy(curr_grid)
    threshold = 4 if part1 else 5
    count, last_count = 0, -1
    while True:
        for i in range(len(curr_grid)):
            for j in range(len(curr_grid[i])):
                if curr_grid[i][j] == 'L' and count_func(last_grid, i, j, part1=part1) == 0:
                    curr_grid[i][j] = '#'
                if curr_grid[i][j] == '#' and count_func(last_grid, i, j, part1=part1) >= threshold:
                    curr_grid[i][j] = 'L'
        count = count_occupied(curr_grid)
        if count == last_count:
            print(count)
            break
        last_count = count
        last_grid = deepcopy(curr_grid)

play(part1=True)
play(part1=False)
