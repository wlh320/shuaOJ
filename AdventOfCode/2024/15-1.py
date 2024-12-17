from copy import deepcopy

line = open("input").read().strip()
lines, moves = line.split("\n\n")
lines = lines.splitlines()
grid = []

for line in lines:
    line = line.strip()
    grid.append(list(line))

N = len(grid)
M = len(grid[0])


def find_start():
    for i in range(N):
        for j in range(M):
            if grid[i][j] == "@":
                return (i, j)
    return (None, None)


def try_move(grid, x, y, m):
    nx, ny = x + m[0], y + m[1]
    if nx < 0 or nx >= N or ny < 0 or ny >= M:
        return (grid, x, y)

    if grid[nx][ny] == '#':
        return (grid, x, y)

    i, j = nx, ny
    while 0 <= i < N and 0 <= j < M and grid[i][j] == 'O':
        i += m[0]
        j += m[1]

    # move
    if grid[nx][ny] == 'O' and 0 <= i < N and 0 <= j < M and grid[i][j] == '.':
        grid[nx][ny] = '.'
        grid[i][j] = 'O'

    if grid[nx][ny] == '.':
        grid[x][y] = '.'
        x, y = x + m[0], y + m[1]
        grid[x][y] = '@'

    return (grid, x, y)


(x, y) = find_start()


def print_grid(grid, m):
    print(f'Move {m}')
    for i in range(N):
        line = "".join(grid[i])
        print(line)
    print()


for m in moves:
    temp_grid = deepcopy(grid)
    if m == "^":
        temp_grid, x, y = try_move(temp_grid, x, y, (-1, 0))
    elif m == "v":
        temp_grid, x, y = try_move(temp_grid, x, y, (1, 0))
    elif m == "<":
        temp_grid, x, y = try_move(temp_grid, x, y, (0, -1))
    elif m == ">":
        temp_grid, x, y = try_move(temp_grid, x, y, (0, 1))
    grid = temp_grid
    # print_grid(grid, m)


ans = 0
for i in range(N):
    for j in range(M):
        if grid[i][j] == 'O':
            ans += 100 * i + j
print(ans)
