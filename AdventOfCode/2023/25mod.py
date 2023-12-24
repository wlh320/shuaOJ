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


cuts = nx.minimum_edge_cut(G)
G.remove_edges_from(cuts)

ans = [len(c) for c in nx.connected_components(G)]
assert len(ans) == 2
print(ans[0] * ans[1])
