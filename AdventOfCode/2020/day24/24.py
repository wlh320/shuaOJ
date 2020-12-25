lines = open('input').readlines()

blacks = set()
# e, se, sw, w, nw, and ne
# (x, y)
# https://www.redblobgames.com/grids/hexagons/
M = {'e': (1, 0), 'w': (-1, 0), 'ne': (0, 1),
     'nw': (-1, 1), 'sw': (0, -1), 'se': (1, -1)}
for line in lines:
    line = line.strip()
    cell = [0, 0]
    cont = False
    for i, ch in enumerate(line):
        if cont:
            cont = False
            continue
        if ch == 's' or ch == 'n':
            cont = True
            dx, dy = M[line[i: i+2]]
        else:
            dx, dy = M[ch]
        cell[0] += dx
        cell[1] += dy
    if tuple(cell) in blacks:
        blacks.remove(tuple(cell))
    else:
        blacks.add(tuple(cell))
print(len(blacks))

# 2
for _ in range(100):
    # new_blacks = set() # blacks to be filled of this round
    new_blacks = set()
    alls = set()  # cells need to be checked
    for (x, y) in blacks:
        alls.add((x, y))
        for k, v in M.items():
            dx, dy = v[0], v[1]
            alls.add((x+dx, y+dy))
    for (x, y) in alls:
        n = 0
        for k, v in M.items():
            dx, dy = v[0], v[1]
            if (x+dx, y+dy) in blacks:
                n += 1
        if (x, y) in blacks and not (n == 0 or n > 2):
            new_blacks.add((x, y))
        if (x, y) not in blacks and n == 2:
            new_blacks.add((x, y))
    blacks = new_blacks
print(len(blacks))
