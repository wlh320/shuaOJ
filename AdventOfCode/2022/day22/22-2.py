from copy import deepcopy
import re
data = open('input').read()
map, path = data.split('\n\n')
map, path = map.splitlines(), path.strip()
R, C = len(map), 0
for line in map:
    C = max(C, len(line))
grid = [[' ' for _ in range(C)] for _ in range(R)]
for r, line in enumerate(map):
    for c, v in enumerate(line):
        grid[r][c] = v

path = re.split(re.compile(r'([LR])'), path)


def print_grid(grid):
    for line in grid:
        print(''.join(line))
    print()


r, c = 0, 0
#      right,  down,  left,  up
D = [(0, 1), (1, 0), (0, -1), (-1, 0)]
DS = ['>', 'v', '<', '^']
d = 0

# my cube
#       1   2
#       3
#   4   5
#   6
#
RGHT = 0
DOWN = 1
LEFT = 2
UP = 3


def gen_cmap_test():
    cubes = {1: (0, 2*W), 2: (W, 0), 3: (W, W),
             4: (W, 2*W), 5: (2*W, 2*W), 6: (2*W, 3*W)}

    E = {k: gen_4_edges(*v) for k, v in cubes.items()}
    # map from (src, dim, fix, v1) -> (dim, fix, v1, rev)
    CMAP = {}

    gen_entry(E, CMAP, 1, UP, 2, UP, True)
    gen_entry(E, CMAP, 1, LEFT, 3, UP, False)
    gen_entry(E, CMAP, 1, RGHT, 6, RGHT, True)
    gen_entry(E, CMAP, 2, LEFT, 6, DOWN, True)
    gen_entry(E, CMAP, 2, DOWN, 5, DOWN, True)
    gen_entry(E, CMAP, 3, DOWN, 5, LEFT, True)
    gen_entry(E, CMAP, 4, RGHT, 6, UP, True)

    return E, CMAP


def gen_cmap():
    cubes = {1: (0, W), 2: (0, 2*W), 3: (W, W),
             4: (2*W, 0), 5: (2*W, W), 6: (3*W, 0)}

    E = {k: gen_4_edges(*v) for k, v in cubes.items()}
    # map from (src, dim, fix, v1) -> (dim, fix, v1, rev)
    CMAP = {}
    gen_entry(E, CMAP, 1, UP, 6, LEFT, False)
    gen_entry(E, CMAP, 1, LEFT, 4, LEFT, True)
    gen_entry(E, CMAP, 2, UP, 6, DOWN, False)
    gen_entry(E, CMAP, 2, RGHT, 5, RGHT, True)
    gen_entry(E, CMAP, 2, DOWN, 3, RGHT, False)
    gen_entry(E, CMAP, 3, LEFT, 4, UP, False)
    gen_entry(E, CMAP, 5, DOWN, 6, RGHT, False)

    return E, CMAP


def oppo(d):
    return (d + 2) % len(D)


def in_range(r, c, dim, fix, v1):
    if dim == 0:
        return r == fix and v1 <= c < v1 + W
    else:
        return c == fix and v1 <= r < v1 + W


def to_new_pos(v, dim, fix, v1, rev):
    if dim == 0:
        nr = fix
        nc = v1 + v if not rev else v1 + W - 1 - v
        return nr, nc
    else:
        nc = fix
        nr = v1 + v if not rev else v1 + W - 1 - v
        return nr, nc


def gen_entry(E, cmap, src, srcd, dst, dstd, rev):
    cmap[(src, E[src][srcd], srcd)] = ((*E[dst][dstd], rev), oppo(dstd))
    cmap[(dst, E[dst][dstd], dstd)] = ((*E[src][srcd], rev), oppo(srcd))


def gen_4_edges(lr, lc):
    return {UP: (0, lr, lc), DOWN: (0, lr + W - 1, lc),
            LEFT: (1, lc, lr), RGHT: (1, lc + W - 1, lr)}


def find_next_pos(r, c, d):
    for k, v in CMAP.items():
        src, rng, td = k
        if d == td and in_range(r, c, *rng):
            args, nd = v
            if rng[0] == 0:  # row is fixed
                c -= E[src][UP][2]
                nr, nc = to_new_pos(c, *args)
            else:  # col is fixed
                r -= E[src][UP][1]
                nr, nc = to_new_pos(r, *args)
            return nr, nc, nd
    return r, c, d  # don't change


# find start
xr, xc = r, c
while True:
    xr, xc = xr + D[d][0], xc + D[d][1]
    xr, xc = xr % R, xc % C
    if grid[xr][xc] == '.':
        r, c = xr, xc
        break

W = 50
E, CMAP = gen_cmap()

debug = deepcopy(grid)

for p in path:
    if p == 'L':
        d = (d - 1) % len(D)
    elif p == 'R':
        d = (d + 1) % len(D)
    else:
        p = int(p)
        for _ in range(p):
            nr, nc, nd = find_next_pos(r, c, d)
            if r != nr or c != nc:  # check if is out of board
                if grid[nr][nc] == '#':
                    break
                elif grid[nr][nc] == '.':
                    debug[r][c] = DS[d]
                    r, c, d = nr, nc, nd
                    # print_grid(debug)
            else:
                nr, nc = r + D[d][0], c + D[d][1]
                if grid[nr][nc] == '#':
                    break
                elif grid[nr][nc] == '.':
                    debug[r][c] = DS[d]
                    r, c = nr, nc
                    # print_grid(debug)

ans = (r+1) * 1000 + (c+1) * 4 + d
print(ans)
