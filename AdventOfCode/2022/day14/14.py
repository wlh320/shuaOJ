data = open('input').read().splitlines()
R, C = 600, 600
grid = [['.' for _ in range(C)] for _ in range(R)]
for line in data:
    # print(line)
    xys = line.split('->')
    walls = []
    for xy in xys:
        xy = xy.split(',')
        # x -> col y -> row
        x, y = int(xy[0]), int(xy[1])
        R, C = max(R, x), max(C, y)
        walls.append((y, x))

    for w, w1 in zip(walls, walls[1:]):
        if w[0] == w1[0]:
            for x in range(min(w[1], w1[1]), max(w[1], w1[1]) + 1):
                grid[w[0]][x] = '#'
        elif w[1] == w1[1]:
            for y in range(min(w[0], w1[0]), max(w[0], w1[0]) + 1):
                grid[y][w[1]] = '#'


def print_grid():
    # RL, RR = 494, 504
    # CL, CR = 0, 10
    CL, CR = 30, 200
    RL, RR = 450, 504
    for r in range(CL, CR):
        line = ''.join([grid[r][c] for c in range(RL, RR)])
        print(line)
    print()


def sand_drop(r, c) -> tuple[int, int] | None:
    while True:
        cr, cc = None, None
        for nr, nc in [(r + 1, c), (r + 1, c - 1), (r + 1, c + 1)]:
            if nc < 0 or nc > C - 1 or nr < 0 or nr > R - 1:
                return None, None
            if grid[nr][nc] == '.':
                cr, cc = nr, nc
                break
        # cannot move
        if cr is None and cc is None:
            grid[r][c] = 'x'
            return (r, c)
        # out of board
        elif cc < 0 or cc > C - 1 or cr > R:
            return None, None
        r, c = cr, cc

    return None, None


i = 0
while True:
    nr, nc = sand_drop(0, 500)
    i += 1
    # print_grid()
    if (nr, nc) == (None, None):
        print(i - 1)
        break
