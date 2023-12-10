s = open("input").read().strip()
# s = open('input1').read().strip()

ins, lines = s.split("\n\n")
ins = ins.strip()
lines = lines.splitlines()

maps = dict()

for line in lines:
    s, next = line.split(" = ")
    l, r = next.split(", ")
    l = l[1:]
    r = r[:-1]
    maps[s] = (l, r)


# 1
cnt = 0
c = "AAA"
final = "ZZZ"
n = len(ins)
while c != final:
    d = ins[cnt % n]
    if d == "L":
        c = maps[c][0]
    elif d == "R":
        c = maps[c][1]
    cnt += 1
print(cnt)


# 2
nodes = []
for k in maps.keys():
    if k.endswith("A"):
        nodes.append(k)


def walk_one(curr):
    cnt = 0
    n = len(ins)
    while not curr.endswith("Z"):
        d = ins[cnt % n]
        if d == "L":
            next = maps[curr][0]
        else:
            next = maps[curr][1]

        curr = next
        cnt += 1
    return cnt


import math

ans = 1
for node in nodes:
    cnt = walk_one(node)
    ans = math.lcm(ans, cnt)
print(ans)
