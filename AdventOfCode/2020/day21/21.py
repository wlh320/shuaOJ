from collections import defaultdict
from copy import deepcopy
lines = open('input').readlines()
def split_input(line):
    line = line.strip()
    gres, als = line.split('(contains ')
    gres = gres.split()
    als = als[:-1].split(', ')
    return gres, als
 
Gs = set()
As = set()
cnt = defaultdict(int)
for line in lines: # count
    gres, als = split_input(line)
    Gs |= set(gres)
    As |= set(als)
    for g in gres:
        cnt[g] += 1

notin = {g: set() for g in Gs}
for line in lines:
    gres, als = split_input(line)
    for a in als: # this al
        for g in Gs:
            if g not in gres: # ingrediants not in this line must have no this al
                notin[g].add(a)
ans = 0
for g in Gs:
    if notin[g] == As:
        ans += cnt[g]
print(ans)

# 2 
# just like this year's another problem that match ticket field
suspect = {g: deepcopy(As)-notin[g] for g in Gs if notin[g] != As}
kv = []
while len(kv) != len(As):
    for g in suspect:
        if len(suspect[g]) == 1:
            kv.append((g, suspect[g].pop()))
            for gg in suspect:
                if g != gg:
                    if kv[-1][-1] in suspect[gg]:
                        suspect[gg].remove(kv[-1][-1])
ans2 = ','.join(map(lambda x: x[0], sorted(kv, key=lambda x: x[1])))
print(ans2)
