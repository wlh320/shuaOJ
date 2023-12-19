input = open("input").read().strip()
# input = open("input1").read().strip()

bricks = []
lines = input.splitlines()
for line in lines:
    s, t = line.split("~")
    s = list(map(int, s.split(",")))
    t = list(map(int, t.split(",")))
    bricks.append((s, t))
bricks.sort(key=lambda x: x[0][2])

filled = set()
for b in bricks:
    start, end = b
    for x in range(start[0], end[0] + 1):
        for y in range(start[1], end[1] + 1):
            for z in range(start[2], end[2] + 1):
                filled.add((x, y, z))


def find_index(x, y, z):
    for i, b in enumerate(bricks):
        start, end = b
        if (
            x in range(start[0], end[0] + 1)
            and y in range(start[1], end[1] + 1)
            and z in range(start[2], end[2] + 1)
        ):
            return i
    return -1


supported = dict()

for i, b in enumerate(bricks):
    start, end = b

    # fall
    def fall(start, end):
        z = start[2]
        sup = set()
        while True:
            ok = True
            for x in range(start[0], end[0] + 1):
                for y in range(start[1], end[1] + 1):
                    if (x, y, z - 1) in filled:
                        ok = False
                        idx = find_index(x, y, z - 1)
                        sup.add(idx)
            if z - 1 <= 0:
                return z, sup
            if not ok:
                return z, sup
            z -= 1

    nz, sup = fall(start, end)
    supported[i] = sup

    for x in range(start[0], end[0] + 1):
        for y in range(start[1], end[1] + 1):
            for z in range(start[2], end[2] + 1):
                filled.remove((x, y, z))
                filled.add((x, y, z - start[2] + nz))

    start[2], end[2] = nz, end[2] - start[2] + nz
    end[2] = end[2] - start[2] + nz
    bricks[i] = (start, end)


# 1
ans = 0
for i in range(len(bricks)):
    ok = True
    for j, s in supported.items():
        if i in s and len(s) == 1:
            ok = False
            break
    if ok:
        ans += 1
print(ans)

# 2
from collections import deque
from copy import deepcopy


def remove_chain(x):
    tmp = deepcopy(supported)
    cnt = 0
    q = deque([x])
    while q:
        b = q.popleft()
        cnt += 1
        for j, s in tmp.items():
            if b in s:
                s.remove(b)
                if len(s) == 0:
                    q.append(j)
    return cnt - 1


ans = 0
for i in range(len(bricks)):
    x = remove_chain(i)
    ans += x

print(ans)
