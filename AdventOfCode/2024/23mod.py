from collections import defaultdict

lines = open("input").read().splitlines()

G = defaultdict(set)
grps = set()
for line in lines:
    a, b = line.split("-")
    G[a].add(b)
    G[b].add(a)
    grps.add(tuple(sorted([a, b])))

n = 2
while len(grps) != 1:
    if n == 3:
        ans1 = len([g for g in grps if any(x.startswith("t") for x in g)])
        print(ans1)

    new_grps = set()
    for grp in grps:
        to_add = set.intersection(*[G[x] for x in grp]) - set(grp)
        for x in to_add:
            new_grps.add(tuple(sorted(list(grp + (x,)))))
    grps = new_grps
    n += 1

ans2 = ",".join(grps.pop())
print(ans2)
