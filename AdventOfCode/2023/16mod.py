from collections import deque

input = open("input").read().strip()
# input = open("input1").read().strip()
UP, DOWN, LEFT, RIGHT = (-1, 0), (1, 0), (0, -1), (0, 1)

grid = input.splitlines()
n, m = len(grid), len(grid[0])


def mirror_reflect(mirror, dir):
    di, dj = dir
    assert mirror == "/" or mirror == "\\"
    return {"/": (-dj, -di), "\\": (dj, di)}[mirror]


# 1
def run(si, sj, sd):
    vis = set([])
    q = deque([])
    q.append((si, sj, sd))

    while q:
        i, j, dir = q.popleft()
        di, dj = dir
        ni, nj = i + di, j + dj
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            continue
        if (ni, nj, dir) in vis:
            continue
        vis.add((ni, nj, dir))

        go = lambda dir: q.append((ni, nj, dir))
        STRAIGHT = dir

        match grid[ni][nj]:
            case ".":
                go(STRAIGHT)
            case "/" | "\\":
                mirror = grid[ni][nj]
                go(mirror_reflect(mirror, dir))
            case "|" if dir == UP or dir == DOWN:
                go(STRAIGHT)
            case "-" if dir == LEFT or dir == RIGHT:
                go(STRAIGHT)
            case "|":
                go(UP)
                go(DOWN)
            case "-":
                go(LEFT)
                go(RIGHT)

    ans = set()
    for i, j, dir in vis:
        ans.add((i, j))

    return len(ans)


# 1
si, sj, sd = 0, -1, (0, 1)
ans = run(si, sj, sd)
print(ans)


# 2
ans = 0
for j in range(m):
    r1 = run(-1, j, (1, 0))
    ans = max(ans, r1)
    r2 = run(n, j, (-1, 0))
    ans = max(ans, r2)

for i in range(n):
    r1 = run(i, -1, (0, 1))
    ans = max(ans, r1)
    r2 = run(i, 0, (0, -1))
    ans = max(ans, r2)
print(ans)
