from copy import deepcopy
from collections import Counter


lines = open("input").readlines()


ps = []
vs = []
for line in lines:
    line = line.strip().split("=")
    p = line[1].split()[0].split(",")
    v = line[2].split(",")
    p = list(map(int, p))
    v = list(map(int, v))
    ps.append(p)
    vs.append(v)


XB, YB = 101, 103


def move(p, v):
    # x -> right, y -> down
    x, y = p
    vx, vy = v
    x = (x + vx) % XB
    if x < 0:
        x += XB
    y = (y + vy) % YB
    if y < 0:
        y += YB
    return (x, y)


def print_grid(t, s):
    print(f"T={t}")
    for y in range(YB):
        line = ""
        for x in range(XB):
            if (x, y) in s:
                line += "#"
            else:
                line += " "
        print(line)
    print()


def hash(pos):
    s = ""
    for p in pos:
        s += f"({p[0]},{p[1]})"
    return s


def simulate(T, ps, vs, print_pic=False):
    hist = {}
    ps = deepcopy(ps)
    vs = deepcopy(vs)
    for t in range(1, T + 1):

        for i in range(len(ps)):
            pp = move(ps[i], vs[i])
            ps[i] = pp

        pos = deepcopy(ps)

        if hash(pos) in hist:
            return t

        hist[hash(pos)] = t
        if print_pic:
            print_grid(t, set(pos))

    return pos


# 1
T = 100
pos = simulate(T, ps, vs)
c = Counter(pos)

c1, c2, c3, c4 = 0, 0, 0, 0
midx = XB // 2
midy = YB // 2
for k, v in c.items():
    x, y = k
    if 0 <= x < midx and 0 <= y < midy:
        c1 += v
    elif midx < x < XB and 0 <= y < midy:
        c2 += v
    elif 0 <= x < midx and midy < y < YB:
        c3 += v
    elif midx < x < XB and midy < y < YB:
        c4 += v

print(c1 * c2 * c3 * c4)

# 2
T = 100000
t = simulate(T, ps, vs)
print(t)

T = t
simulate(T, ps, vs, print_pic=True)
# print it out, search ############ using vim
