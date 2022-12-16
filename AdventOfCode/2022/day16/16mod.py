import re
from collections import defaultdict


def floyd_warshall(G, V):
    """
    G: dict[node, iterable((node, weight))]
    V: iterable(node)
    num_v: number of vertices
    return dict[dict[node, path length]]
    time complexity is O(V^3)
    """
    # adj list -> adj matrix
    ADJ = {u: {v: float('inf') for v in V} for u in V}
    for u in V:
        ADJ[u][u] = 0
        for v, weight in G[u]:
            ADJ[u][v] = weight

    # init dist
    dist = {v: {} for v in V}
    for u in V:
        for v in V:
            dist[u][v] = ADJ[u].get(v, float('inf'))

    # V^3 relaxion loop
    for k in V:
        for i in V:
            for j in V:
                if (dist[i][k] != float('inf')
                    and dist[k][j] != float('inf')
                        and dist[i][k] + dist[k][j] < dist[i][j]):
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist


PTN = re.compile(
    r'Valve ([A-Z]+) has flow rate=(\d+); tunnels? leads? to valves? (.+)')

G = defaultdict(set)
R = {}

data = open('input').read().splitlines()
for line in data:
    name, rate, edges = re.findall(PTN, line)[0]
    edges = edges.split(', ')
    # print(name, rate, edges)
    R[name] = int(rate)
    for dst in edges:
        G[name].add((dst, 1))
        G[dst].add((name, 1))

V = R.keys()
DIST = floyd_warshall(G, V)

# print(DIST)

nodes = [v for v in V if R[v] != 0]
nodes.sort()

memo = {}
T = 26


def dfs(time: int, v: str, node_set: tuple) -> int:
    if time > T:
        return 0
    if not node_set:
        return R[v] * max(T - time - 1, 0)
    if (time, v, node_set) in memo:
        return memo[(time, v, node_set)]
    ans = 0

    val = R[v] * max(T - time - 1, 0)
    open_time = 0 if v == 'AA' else 1
    for t in node_set:
        walk_time = DIST[v][t]
        next_set = tuple(x for x in node_set if x != t)
        new_ans = val + dfs(time + open_time + walk_time, t, next_set)
        ans = max(ans, new_ans)
    memo[(time, v, node_set)] = ans
    return ans


# part1
T = 30
s = tuple(nodes)
ans = dfs(0, 'AA', s)
print(ans)


# part2 slow 20s
T = 26
ans = 0
node_set = tuple(nodes)
for idx in range(2**len(node_set)):
    s1 = tuple(x for i, x in enumerate(node_set) if (idx & (1 << i)))
    s2 = tuple(x for i, x in enumerate(node_set) if not (idx & (1 << i)))
    ans1 = dfs(0, 'AA', s1)
    ans2 = dfs(0, 'AA', s2)
    ans = max(ans, ans1 + ans2)
print(ans)
