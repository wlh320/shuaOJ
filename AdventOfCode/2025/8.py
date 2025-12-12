import math
from collections import defaultdict
from queue import PriorityQueue

lines = open("input").read().splitlines()
points = [tuple(map(int, line.split(","))) for line in lines]
n = len(points)


def dis(p1, p2):
    d1 = (p1[0] - p2[0]) ** 2
    d2 = (p1[1] - p2[1]) ** 2
    d3 = (p1[2] - p2[2]) ** 2
    return math.sqrt(d1 + d2 + d3)


def calc_pq():
    pq = PriorityQueue(n * (n - 1) // 2)
    for i in range(n):
        for j in range(i + 1, n):
            pq.put((dis(points[i], points[j]), i, j))
    return pq


def find(parent, x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x


def union(parent, a, b):
    x = find(parent, a)
    y = find(parent, b)
    parent[x] = y


# 1
parent = [i for i in range(n)]
N = 1000
pq = calc_pq()
for _ in range(N):
    _, i, j = pq.get()
    union(parent, i, j)

groups = defaultdict(int)
for p in parent:
    groups[find(parent, p)] += 1
vs = sorted(list(set(groups.values())), reverse=True)
print(vs[0] * vs[1] * vs[2])

# 2
parent = [i for i in range(n)]
while not pq.empty():
    _, i, j = pq.get()
    union(parent, i, j)

    groups = defaultdict(int)
    for p in parent:
        groups[find(parent, p)] += 1
    if len(groups) == 1:
        print(points[i][0] * points[j][0])
        break
