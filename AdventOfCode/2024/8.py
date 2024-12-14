from collections import defaultdict

lines = open("input").readlines()

grid = []
for line in lines:
    line = list(line.strip())
    grid.append(line)

n = len(grid)
m = len(grid[0])


d = defaultdict(list)
for i in range(n):
    for j in range(m):
        x = grid[i][j]
        if x != ".":
            d[x].append((i, j))


s = set()
for x, p in d.items():
    l = len(p)
    for i in range(l):
        for j in range(i + 1):
            x1, y1 = p[i]
            x2, y2 = p[j]

            p1 = (x1 - (x2 - x1), y1 - (y2 - y1))
            if (0 <= p1[0] < n) and (0 <= p1[1] < m):
                if grid[p1[0]][p1[1]] != x:
                    s.add(p1)
            p2 = (x2 + (x2 - x1), y2 + (y2 - y1))
            if (0 <= p2[0] < n) and (0 <= p2[1] < m):
                if grid[p2[0]][p2[1]] != x:
                    s.add(p2)
print(len(s))

# 2
for x, p in d.items():
    l = len(p)
    for i in range(l):
        for j in range(i + 1, l):

            x1, y1 = p[i]
            x2, y2 = p[j]

            dx = x2 - x1
            dy = y2 - y1

            p1x, p1y = x1, y1
            while (0 <= p1x < n) and (0 <= p1y < m):
                s.add((p1x, p1y))
                p1x -= dx
                p1y -= dy

            p2x, p2y = x2, y2
            while (0 <= p2x < n) and (0 <= p2y < m):
                s.add((p2x, p2y))
                p2x += dx
                p2y += dy

print(len(s))
