from queue import PriorityQueue

input = open("input").read().strip()
# input = open("input1").read().strip()

lines = input.splitlines()

grid = []
for line in lines:
    line = list(map(int, list(line)))
    grid.append(line)

n, m = len(grid), len(grid[0])

DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def priority_bfs(can_keep_moving, can_turn):
    pq = PriorityQueue()
    pq.put((0, (0, 0, -1, 0)))
    cache = dict()
    while not pq.empty():
        (curr, (i, j, d, cnt)) = pq.get()
        if not can_keep_moving(cnt):
            continue
        if (i, j, d, cnt) in cache and curr >= cache[(i, j, d, cnt)]:
            continue
        else:
            cache[(i, j, d, cnt)] = curr

        for dir in range(len(DIRS)):
            di, dj = DIRS[dir]
            ni, nj = i + di, j + dj
            if ni < 0 or ni >= n or nj < 0 or nj >= m:
                continue
            if (dir + 2) % 4 == d:
                continue
            if dir == d:
                pq.put((curr + grid[ni][nj], (ni, nj, dir, cnt + 1)))
            elif d == -1 or can_turn(cnt):
                pq.put((curr + grid[ni][nj], (ni, nj, dir, 1)))

    ans = 10**10
    for k, v in cache.items():
        i, j, d, cnt = k
        if i == n - 1 and j == m - 1 and can_turn(cnt):
            ans = min(ans, v)
    return ans


# 1
can_keep_moving = lambda cnt: 0 <= cnt <= 3
can_turn = lambda _: True
ans = priority_bfs(can_keep_moving, can_turn)
print(ans)

# 2
can_keep_moving = lambda cnt: 0 <= cnt <= 10
can_turn = lambda cnt: cnt >= 4
ans = priority_bfs(can_keep_moving, can_turn)
print(ans)
