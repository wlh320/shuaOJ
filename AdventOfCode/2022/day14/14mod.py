from copy import deepcopy
data = open('input').read().splitlines()
R, C = 700, 700
MR, MC = 0, 0
grid = [['.' for _ in range(C)] for _ in range(R)]

for line in data:
    xys = line.split('->')
    walls = []
    for xy in xys:
        xy = xy.split(',')
        # x: col y: row
        x, y = int(xy[0]), int(xy[1])
        MR, MC = max(MR, y), max(MC, x)
        walls.append((y, x))

    for w, w1 in zip(walls, walls[1:]):
        if w[0] == w1[0]:
            for x in range(min(w[1], w1[1]), max(w[1], w1[1]) + 1):
                grid[w[0]][x] = '#'
        elif w[1] == w1[1]:
            for y in range(min(w[0], w1[0]), max(w[0], w1[0]) + 1):
                grid[y][w[1]] = '#'

BACKUP = deepcopy(grid)


def drop_sand(r: int, c: int, part: int):
    while True:
        cr, cc = None, None
        for nr, nc in [(r + 1, c), (r + 1, c - 1), (r + 1, c + 1)]:
            if part == 1 and (nc < 0 or nc > C - 1 or nr > R - 1):
                return None, None
            if grid[nr][nc] == '.':
                cr, cc = nr, nc
                break
        # cannot move
        if cr is None and cc is None:
            break
        r, c = cr, cc

    grid[r][c] = 'x'
    return (r, c)


# part 1
ans = 0
grid = deepcopy(BACKUP)
while True:
    nr, nc = drop_sand(0, 500, 1)
    ans += 1
    # print_grid()
    if (nr, nc) == (None, None):
        print(ans - 1)
        break

# part2
grid = deepcopy(BACKUP)
for c in range(0, C):
    grid[MR + 2][c] = '#'
MR += 2

ans = 0
while True:
    nr, nc = drop_sand(0, 500, 2)
    ans += 1
    if (nr, nc) == (0, 500):
        print(ans)
        break
