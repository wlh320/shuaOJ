import z3

input = open("input").read().strip()
# input = open("input1").read().strip()

grid = []
lines = input.splitlines()
hails = []
for line in lines:
    pos, v = line.split(" @ ")
    pos = list(map(int, pos.split(",")))
    v = list(map(int, v.split(",")))
    hails.append((pos, v))

n = len(hails)


# copy from stackoverflow
def findIntersection(x1, y1, x2, y2, x3, y3, x4, y4):
    try:
        px = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / (
            (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
        )
        py = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / (
            (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
        )
        return [px, py]
    except Exception:
        return None


ans = 0
LO = 200000000000000
HI = 400000000000000

for i in range(n):
    pos_i, v_i = hails[i]
    A = (pos_i[0], pos_i[1])
    B = (pos_i[0] + v_i[0], pos_i[1] + v_i[1])

    for j in range(i + 1, n):
        pos_j, v_j = hails[j]
        C = (pos_j[0], pos_j[1])
        D = (pos_j[0] + v_j[0], pos_j[1] + v_j[1])

        x = findIntersection(A[0], A[1], B[0], B[1], C[0], C[1], D[0], D[1])

        if x is None:
            continue
        if (x[0] - A[0]) * (B[0] - A[0]) < 0:
            continue
        if (x[1] - A[1]) * (B[1] - A[1]) < 0:
            continue
        if (x[0] - C[0]) * (D[0] - C[0]) < 0:
            continue
        if (x[1] - C[1]) * (D[1] - C[1]) < 0:
            continue

        if LO <= x[0] <= HI and LO <= x[1] <= HI:
            ans += 1
print(ans)

# 2
exps = []

x0 = z3.Int("x0")
y0 = z3.Int("y0")
z0 = z3.Int("z0")

vx0 = z3.Int("vx0")
vy0 = z3.Int("vy0")
vz0 = z3.Int("vz0")
for pos, v in hails:
    x, y, z = pos
    vx, vy, vz = v

    exps.append((x0 - x) * (vy0 - vy) == (vx0 - vx) * (y0 - y))
    exps.append((y0 - y) * (vz0 - vz) == (vy0 - vy) * (z0 - z))

z3.solve(exps)
