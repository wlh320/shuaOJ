from collections import defaultdict
from queue import PriorityQueue

lines = open("input").readlines()

grid = []
for line in lines:
    grid.append(list(line.strip()))

n = len(grid)
m = len(grid[0])


def find_se():
    s, e = None, None
    for i in range(n):
        for j in range(m):
            if grid[i][j] == "S":
                s = (i, j)
            elif grid[i][j] == "E":
                e = (i, j)
    return s, e


s, e = find_se()
assert s != (None, None)
assert e != (None, None)

ds = [(0, 1), (-1, 0), (0, -1), (1, 0)]
min_score = {(*s, 0): 0}
final_score = None
parents = defaultdict(set)
parents[(*s, 0)] = (*s, 0)


st = set()
def backtrack(p, parents):
    if p == (*s, 0):
        return
    for par in parents[p]:
        st.add((par[0], par[1]))
        backtrack(par, parents)


q = PriorityQueue()
q.put((0, s, 0))
while q:
    score, (i, j), d = q.get()

    if (i, j) == e:
        if final_score is not None and score > final_score:
            # 1
            print(final_score)
            break
        final_score = score
        st.add(e)
        backtrack((i, j, d), parents)

    # go straight
    di, dj = ds[d]
    ni, nj = i + di, j + dj
    if ni >= 0 and ni < n and nj >= 0 and nj < m:
        if grid[ni][nj] != "#":
            ns = score + 1
            if (ni, nj, d) in min_score and ns > min_score[(ni, nj, d)]:
                continue

            min_score[(ni, nj, d)] = ns
            if ns == min_score[(ni, nj, d)]:
                parents[(ni, nj, d)].add((i, j, d))
            else:
                parents[(ni, nj, d)] = set([(i, j, d)])
            q.put((ns, (ni, nj), d))

    # turn left or right
    for d1 in [(d + 1) % 4, (d - 1 + 4) % 4]:
        ns = score + 1000
        if (i, j, d1) in min_score and ns > min_score[(i, j, d1)]:
            continue

        min_score[(i, j, d1)] = ns
        if ns == min_score[(i, j, d1)]:
            parents[(i, j, d1)].add((i, j, d))
        else:
            parents[(i, j, d1)] = set([(i, j, d)])
        q.put((ns, (i, j), d1))

# 2
print(len(st))
