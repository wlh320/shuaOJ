from copy import deepcopy

line = open("input").read().strip()
lines, moves = line.split("\n\n")
lines = lines.splitlines()
grid = []

for line in lines:
    line = line.strip()
    line = line.replace("#", "##")
    line = line.replace("O", "[]")
    line = line.replace(".", "..")
    line = line.replace("@", "@.")

    grid.append(list(line))

N = len(grid)
M = len(grid[0])


def find_start():
    for i in range(N):
        for j in range(M):
            if grid[i][j] == "@":
                return (i, j)
    return (None, None)


def is_box(grid, i, j):
    return grid[i][j] in "[]"


def try_move(grid, x, y, m):
    nx, ny = x + m[0], y + m[1]
    if nx < 0 or nx >= N or ny < 0 or ny >= M:
        return (grid, x, y)

    if grid[nx][ny] == "#":
        return (grid, x, y)

    if m in [(0, -1), (0, 1)]:
        # move horizontal
        i, j = nx, ny
        while 0 <= i < N and 0 <= j < M and is_box(grid, i, j):
            i += m[0]
            j += m[1]

        if is_box(grid, nx, ny) and 0 <= i < N and 0 <= j < M and grid[i][j] == ".":
            start = min(ny, j - m[1])
            end = max(ny, j - m[1])
            grid[nx][start + m[1] : end + 1 + m[1]] = grid[nx][start : end + 1]
            grid[nx][ny] = "."
    else:
        # move vertical
        cols = []
        if is_box(grid, nx, ny):
            if grid[nx][ny] == "[":
                cols.append((ny, ny + 1))
            elif grid[nx][ny] == "]":
                cols.append((ny - 1, ny))
            i = nx
            while not any(
                [grid[i][j] == "#" for j in range(cols[-1][0], cols[-1][1] + 1)]
            ):
                start, end = cols[-1][0], cols[-1][1]
                while grid[i][start] == ".":
                    start += 1
                while grid[i][end] == ".":
                    end -= 1
                if grid[i][start] == "]":
                    start -= 1
                if grid[i][end] == "[":
                    end += 1
                if start >= end:
                    break
                cols.append((start, end))
                i += m[0]

            # can move
            if all(
                [grid[i][col] == "." for col in range(cols[-1][0], cols[-1][1] + 1)]
            ):
                while i != nx:
                    start, end = cols[-1]
                    grid[i][start : end + 1] = grid[i - m[0]][start : end + 1]
                    grid[i - m[0]][start : end + 1] = ["."] * (end - start + 1)
                    i -= m[0]
                    cols.pop()
                for j in range(cols[-1][0], cols[-1][1] + 1):
                    grid[nx][j] = "."

    if grid[nx][ny] == ".":
        grid[x][y] = "."
        x, y = x + m[0], y + m[1]
        grid[x][y] = "@"

    return (grid, x, y)


(x, y) = find_start()


def print_grid(grid, m):
    print(f"Move {m}")
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


ans = 0
for i in range(N):
    for j in range(M):
        if grid[i][j] == "[":
            ans += 100 * i + j
print(ans)
