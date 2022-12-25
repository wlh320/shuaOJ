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

r, c = 0, 0
#      right,  down,  left,  up
D = [(0, 1), (1, 0), (0, -1), (-1, 0)]
DS = ['>', 'v', '<', '^']
d = 0


# find start
xr, xc = r, c
while True:
    xr, xc = xr + D[d][0], xc + D[d][1]
    xr, xc = xr % R, xc % C
    if grid[xr][xc] == '.':
        r, c = xr, xc
        break
# print(r, c)

for p in path:
    # print(r, c)
    if p == 'L':
        d = (d - 1) % len(D)
    elif p == 'R':
        d = (d + 1) % len(D)
    else:
        p = int(p)
        for _ in range(p):
            nr, nc = r + D[d][0], c + D[d][1]
            if nr < 0 or nr > R - 1 or nc < 0 or nc > C - 1:
                nr = nr % R
                nc = nc % C
            if grid[nr][nc] == '#':
                continue
            elif grid[nr][nc] == ' ':
                # find next
                xr, xc = nr, nc
                while True:
                    xr, xc = xr + D[d][0], xc + D[d][1]
                    xr, xc = xr % R, xc % C
                    if grid[xr][xc] == '#':
                        xr, xc = r, c
                        break
                    if grid[xr][xc] == '.':
                        break
                # grid[r][c] = DS[d]
                r, c = xr, xc
                # print_grid(grid)
            elif grid[xr][xc] == '.':
                # grid[r][c] = DS[d]
                r, c = nr, nc
                # print_grid(grid)
grid[r][c] = DS[d]
# print_grid(grid)

# print(r+1, c+1, d)
ans = (r+1) * 1000 + (c+1) * 4 + d
print(ans)
