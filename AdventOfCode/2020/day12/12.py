lines = open('input').readlines()
x, y = 0, 0
#     E   N   W   S
dx = [1,  0, -1,  0]
dy = [0, -1,  0,  1]
myd = 0
for line in lines:
    line = line.strip()
    d, v = line[0], int(line[1:])
    if d == 'N':
        y -= v
    elif d == 'S':
        y += v
    elif d == 'E':
        x += v
    elif d == 'W':
        x -= v
    elif d == 'L':
        v = v // 90
        myd = (myd+v) % 4
    elif d == 'R':
        v = v // 90
        myd = (myd-v) % 4
    elif d == 'F':
        x += dx[myd] * v
        y += dy[myd] * v
print(abs(x)+abs(y))
# 2
x, y = 0, 0
wx, wy = 10, -1
ds = [lambda x, y: ( x,  y), lambda x, y: ( y, -x),
      lambda x, y: (-x, -y), lambda x, y: (-y,  x)]
myd = 0
for line in lines:
    line = line.strip()
    d, v = line[0], int(line[1:])
    if d == 'N':
        wy -= v
    elif d == 'S':
        wy += v
    elif d == 'E':
        wx += v
    elif d == 'W':
        wx -= v
    elif d == 'L':
        v = v // 90
        wx, wy = ds[v%4](wx, wy)
    elif d == 'R':
        v = v // 90
        wx, wy = ds[-v%4](wx, wy)
    elif d == 'F':
        x += wx * v
        y += wy * v
print(abs(x)+abs(y))
