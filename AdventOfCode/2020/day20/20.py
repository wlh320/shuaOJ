lines = open('input').read().split('\n\n')
m = {}

def handle_tile(id, tile):
    top, bot = tile[0], tile[-1]
    lft, rgt = '', ''
    for line in tile:
        lft += line[0]
        rgt += line[-1]
    m[top] = [id] if top not in m else m[top] + [id]
    m[bot] = [id] if bot not in m else m[bot] + [id]
    m[lft] = [id] if lft not in m else m[lft] + [id]
    m[rgt] = [id] if rgt not in m else m[rgt] + [id]
    top, bot = top[::-1], bot[::-1]
    lft, rgt = lft[::-1], rgt[::-1]
    m[top] = [id] if top not in m else m[top] + [id]
    m[bot] = [id] if bot not in m else m[bot] + [id]
    m[lft] = [id] if lft not in m else m[lft] + [id]
    m[rgt] = [id] if rgt not in m else m[rgt] + [id]
 

cnt = 0
for line in lines:
    line = line.split()
    id, tile = int(line[1][:-1]), line[2:]
    cnt += 1
    handle_tile(id, tile)

# 1
degree = {}
for k, v in m.items():
    if len(v) == 2:
        s, t = v
        degree[s] = 1 if s not in degree else degree[s] + 1
        degree[t] = 1 if t not in degree else degree[t] + 1
ans = 1
corners = []
degree_counter = {}
for k, v in degree.items():
    degree_counter[v] = 1 if v not in degree_counter else degree_counter[v] + 1
    if v == 4:
        corners.append(k)
        ans *= k
print(ans)

# 2
# TODO
