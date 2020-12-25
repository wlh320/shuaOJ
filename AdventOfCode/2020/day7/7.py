import re
lines = open('input').readlines()
G = {}
revG = {}
for line in lines[:]:
    line = line.strip()
    parent, children = line.split(' contain ')
    children = children.split(', ')
    parent = ' '.join(parent.split(' ')[:-1])
    for child in children:
        if child == 'no other bags.':
            G[parent] = G.get(parent, {})
            break
        child = child.split(' ')
        n, child = child[0], ' '.join(child[1:-1])
        # for level 1
        revG[child] = revG.get(child, [])
        revG[child].append(parent)
        # for level 2
        G[parent] = G.get(parent, {})
        G[parent][child] = int(n)

# level 1
# bfs
asn = 0
q = ['shiny gold']
parents = set()
while len(q) > 0:
    next_q = []
    for x in q:
        if x not in parents:
            next_q.extend(revG.get(x, []))
        parents.add(x)
    q = next_q
print(len(parents)-1)

# level 2
# dfs
cache = {}
def dfs(G, root) -> int:
    if G[root] == {}:
        return 0
    if root in cache:
        return cache[root]
    count = 0
    for child in G[root]:
        count += dfs(G, child) * G[root][child]
        count += G[root][child]
    cache[root] = count
    return count
print(dfs(G, 'shiny gold'))
