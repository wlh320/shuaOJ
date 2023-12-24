import networkx as nx

input = open("input").read().strip()
# input = open("input1").read().strip()
lines = input.splitlines()

G = nx.Graph()

for line in lines:
    left, rights = line.strip().split(": ")
    rights = rights.split()
    for r in rights:
        G.add_edge(left, r)
        G.add_edge(r, left)


# Unbalanced Kernighan-Lin Algorithm
id = 0
dummies = set()
K = 3
while True:
    partion = nx.community.kernighan_lin_bisection(G)
    # add a dummy node
    G.add_node(id)
    dummies.add(id)
    id += 1

    S = partion[0]
    T = partion[1]
    cut = nx.cut_size(G, S, T)

    if cut == K:
        p1, p2 = partion[0] - dummies, partion[1] - dummies
        print(len(p1) * len(p2))
        break
