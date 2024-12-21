from queue import PriorityQueue
from collections import defaultdict

lines = open("input").read().splitlines()


grid = []
for line in lines:
    grid.append(list(line.strip()))

N = len(grid)
M = len(grid[0])

S = 0, 0
E = 0, 0
for i in range(N):
    for j in range(M):
        if grid[i][j] == "S":
            S = (i, j)
        if grid[i][j] == "E":
            E = (i, j)


def dijkstra():
    pq = PriorityQueue()
    pq.put((0, S[0], S[1]))
    min_dis = defaultdict(lambda: float("inf"))
    parents = {}
    parents[S] = S
    min_dis[(S[0], S[1])] = 0

    while not pq.empty():
        dis, i, j = pq.get()
        if (i, j) == E:
            break
        for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ni, nj = i + di, j + dj
            if ni < 0 or ni >= N or nj < 0 or nj >= M:
                continue
            if grid[ni][nj] == "#":
                continue
            if dis + 1 < min_dis[(ni, nj)]:
                min_dis[(ni, nj)] = dis + 1
                parents[(ni, nj)] = (i, j)
                pq.put((dis + 1, ni, nj))

    return min_dis, parents


# find shortest path
dist, parents = dijkstra()
path = []
p = E
while p != S:
    path.append(p)
    p = parents[p]
path.append(S)
path = path[::-1]


# find cheating position
ans = 0
ans2 = 0
for i in range(len(path)):
    for j in range(i, len(path)):
        step = j - i
        d = abs(path[j][0] - path[i][0]) + abs(path[j][1] - path[i][1])
        saved = step - d
        if saved >= 100:
            if d == 2:
                ans += 1
            if d <= 20:
                ans2 += 1


print(ans)
print(ans2)
