from collections import deque

lines = open("input").read().splitlines()
N = 70 + 1
M = 70 + 1


def build_map(t):
    grid = [["." for _ in range(M)] for _ in range(N)]
    for line in lines[: t + 1]:
        x, y = line.split(",")
        x, y = int(x), int(y)
        grid[y][x] = "#"

    return grid


def can_go(grid, part2=False):
    vis = set()
    end = (N - 1, M - 1)
    q = deque([(0, 0, 0)])
    while q:
        x, y, t = q.popleft()

        if (x, y) == end:
            if not part2:
                print(t)
            return True

        for dx, dy in [(-1, 0), (0, 1), (0, -1), (1, 0)]:
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if (nx, ny) in vis:
                continue
            if grid[nx][ny] == "#":
                continue
            vis.add((nx, ny))
            q.append((nx, ny, t + 1))

    return False


# 1
grid = build_map(1024 - 1)
can_go(grid)


# 2
l, r = 0, len(lines)
while l < r:
    mid = (l + r) // 2
    grid = build_map(mid)
    if can_go(grid, part2=True):
        l = mid + 1
    else:
        r = mid
print(lines[l])
