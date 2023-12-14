from copy import deepcopy

input = open("input").read().strip()
# input = open("input1").read().strip()
lines = input.splitlines()


grid = []
for line in lines:
    line = list(line.strip())
    grid.append(line)


n, m = len(grid), len(grid[0])


def move_north(grid):
    moved = False
    for i in range(1, n):
        for j in range(m):
            if grid[i][j] == "O":
                if grid[i - 1][j] == ".":
                    moved = True
                    grid[i - 1][j] = "O"
                    grid[i][j] = "."
    return moved


def move_south(grid):
    moved = False
    for i in reversed(range(n - 1)):
        for j in range(m):
            if grid[i][j] == "O":
                if grid[i + 1][j] == ".":
                    moved = True
                    grid[i + 1][j] = "O"
                    grid[i][j] = "."
    return moved


def move_west(grid):
    moved = False
    for j in range(1, m):
        for i in range(n):
            if grid[i][j] == "O":
                if grid[i][j - 1] == ".":
                    moved = True
                    grid[i][j - 1] = "O"
                    grid[i][j] = "."
    return moved


def move_east(grid):
    moved = False
    for j in reversed(range(m - 1)):
        for i in range(n):
            if grid[i][j] == "O":
                if grid[i][j + 1] == ".":
                    moved = True
                    grid[i][j + 1] = "O"
                    grid[i][j] = "."
    return moved


def move_loop(grid, move_func):
    moved = True
    while moved:
        moved = move_func(grid)


def cal(grid):
    ans = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == "O":
                ans += n - i
    return ans


def solve1(grid):
    move_loop(grid, move_north)
    ans = cal(grid)
    print(ans)


def solve2(grid):
    hash = lambda grid: "".join("".join(line) for line in grid)

    n = 1000_000_000
    history = dict()
    history[hash(grid)] = 0

    scores = [cal(grid)]

    for i in range(1, n):
        move_loop(grid, move_north)
        move_loop(grid, move_west)
        move_loop(grid, move_south)
        move_loop(grid, move_east)

        h = hash(grid)
        l = 0
        if h in history:
            first = history[h]
            l = i - first

            target = (n - first) % l
            ans = scores[target + first]
            print(ans)
            break

        else:
            history[h] = i
        scores.append(cal(grid))


# 1
solve1(deepcopy(grid))
solve2(deepcopy(grid))
