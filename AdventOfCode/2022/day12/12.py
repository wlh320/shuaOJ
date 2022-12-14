from collections import deque
data = open('input').readlines()
grid = [[x for x in line.strip()] for line in data]
R, C = len(grid), len(grid[0])


def h(i, j):
    match grid[i][j]:
        case 'S': return ord('a')
        case 'E': return ord('z')
        case ch: return ord(ch)


def bfs(start, target):
    q = deque([[*start, 0]])
    step = 0
    vis = set([start])
    while q:
        i, j, step = q.popleft()
        if grid[i][j] == target:
            return step
        for (ti, tj) in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
            if ti < 0 or ti > R - 1 or tj < 0 or tj > C - 1:
                continue
            if (ti, tj) in vis:
                continue
            if (h(i, j) - h(ti, tj)) <= 1:
                vis.add((ti, tj))
                q.append([ti, tj, step + 1])
    return -1


for i in range(R):
    for j in range(C):
        if grid[i][j] == 'E':
            start = (i, j)
            # part 1
            ans = bfs(start, target='S')
            print(ans)
            # part 2
            ans = bfs(start, target='a')
            print(ans)
