from collections import defaultdict

lines = open("input").read().splitlines()

nodes = set()
G = defaultdict(set)
for line in lines:
    a, b = line.split("-")
    nodes.add(a)
    nodes.add(b)
    G[a].add(b)
    G[b].add(a)

# 1
g3 = set()
grps = set()
for a in nodes:
    for b in G[a]:
        for c in [c for c in G[b] if a in G[c]]:
            sg = tuple(sorted([a, b, c]))
            grps.add(sg)
            if any(x.startswith("t") for x in (a, b, c)):
                g3.add(sg)
print(len(g3))


# 2
while len(grps) != 1:
    new_grps = set()
    for grp in grps:
        cands = set.intersection(*[G[x] for x in grp])
        cands -= set(grp)
        for n in cands:
            new_grps.add(tuple(sorted(list(grp + (n,)))))
    grps = new_grps

g = grps.pop()
print(",".join(g))
