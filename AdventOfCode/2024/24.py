from copy import deepcopy
import sys
import networkx as nx
from functools import cache
import random
from tqdm import tqdm


s1, s2 = open("input").read().split("\n\n")
nodes = set()
for line in s2.splitlines():
    line = line.split()
    a, op, b, d = line[0], line[1], line[2], line[4]

    # find unusual output
    # if op == "XOR" and a.isalpha() and b.isalpha() and d.isalpha():
    #     print(line)

    nodes.add(a)
    nodes.add(b)
    nodes.add(d)


def x_y_to_digits(x, y):
    x2 = f"{x:045b}"
    y2 = f"{y:045b}"

    vals = {}
    for i in range(45):
        vals[f"x{i:02}"] = int(x2[44 - i])
        vals[f"y{i:02}"] = int(y2[44 - i])
    return vals


def run(G, x, y, vals=None):
    GG = nx.DiGraph()
    for k, v in G.items():
        a, _, b = v
        GG.add_edge(a, k)
        GG.add_edge(b, k)

    if not nx.is_directed_acyclic_graph(GG):
        return False

    if vals is None:
        vals = x_y_to_digits(x, y)

    @cache
    def dfs(x):
        if x in vals:
            return vals[x]
        a, f, b = G[x]
        va = dfs(a)
        vb = dfs(b)
        v = f(va, vb)
        vals[x] = v
        return v

    ans = ""
    for i in range(45 + 1):
        n = f"z{i:02}"
        ans += str(dfs(n))
    ans = int(ans[::-1], 2)
    return ans


def gen_exchange_pairs():
    # find by hand, output must be generated from xor
    c1 = ["z14", "z18", "z23"]
    c2 = ["hbk", "dbb", "kvn"]
    p = [(x, y) for x in c1 for y in c2]
    pairs = [
        (p[0], p[4], p[8]),
        (p[0], p[5], p[7]),
        (p[1], p[3], p[8]),
        (p[1], p[5], p[6]),
        (p[2], p[3], p[7]),
        (p[2], p[4], p[6]),
    ]

    cands = set()
    for pa in nodes:
        if pa in c1 or pa in c2 or pa.startswith("x") or pa.startswith("y"):
            continue
        for pb in nodes:
            if pa == pb:
                continue
            if pb in c1 or pb in c2 or pb.startswith("x") or pb.startswith("y"):
                continue
            cands.add(tuple(sorted([pa, pb])))

    all_pairs = []
    for p in pairs:
        for c in cands:
            to_change = p + tuple((c,))
            all_pairs.append(to_change)
    return all_pairs


def exchange_and_run(G):
    all_pairs = gen_exchange_pairs()

    for pairs in tqdm(all_pairs):
        newG = deepcopy(G)
        for p1, p2 in pairs:
            newG[p1], newG[p2] = newG[p2], newG[p1]

        check = []
        for _ in range(50):
            x = random.randint(2 << 40, 2 << 44)
            y = random.randint(2 << 40, 2 << 44)
            c = run(newG, x, y) == x + y
            check.append(c)
            if c == False:
                break

        if all(check):
            ans = []
            for p in pairs:
                ans.append(p[0])
                ans.append(p[1])
            print(",".join(sorted(ans)))
            sys.exit(0)


# 1
s1, s2 = open("input").read().split("\n\n")

vals = {}
for line in s1.splitlines():
    a, b = line.split(": ")
    nodes.add(a)
    vals[a] = int(b)

G = {}
for line in s2.splitlines():
    line = line.split()
    a, op, b, d = line[0], line[1], line[2], line[4]
    if op == "AND":
        f = lambda x, y: x & y
    elif op == "OR":
        f = lambda x, y: x | y
    elif op == "XOR":
        f = lambda x, y: x ^ y
    G[d] = (a, f, b)

ans = run(G, None, None, vals)
print(ans)

# 2
exchange_and_run(G)
