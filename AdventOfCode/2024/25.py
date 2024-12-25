lines = open('input').read()
maps = lines.split('\n\n')

locks = []
keys = []

for m in maps:
    m = m.splitlines()
    if m[0] == "#####":
        rg = range(1, len(m))
        tgt = locks
    else:
        rg = range(0, len(m) - 1)
        tgt = keys

    v = [0] * 5
    for i in rg:
        for j in range(len(m[0])):
            if m[i][j] == '#':
                v[j] += 1
    tgt.append(v)

ans = 0
for l in locks:
    for k in keys:
        ok = [l[i] + k[i] <= 5 for i in range(5)]
        if all(ok):
            ans += 1
print(ans)
