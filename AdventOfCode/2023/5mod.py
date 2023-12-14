input = open("input").read().strip()
# input = open("input1").read().strip()

lines = input.split("\n\n")
seeds, maps = lines[0], lines[1:]

seeds = list(map(int, seeds.split(": ")[1].split()))

# parse to -> [(src, dst, len)]
maps = [m.splitlines()[1:] for m in maps]
maps = [[list(map(int, entry.split())) for entry in m] for m in maps]
maps = [sorted(m, key=lambda x: (x[1], x[0])) for m in maps]
maps = [[(e[1], e[0], e[2]) for e in m] for m in maps]


def search1(seed):
    res = seed
    for m in maps:
        for src, dst, l in m:
            if src <= res < src + l:
                res = dst + (res - src)
                break
    return res


# 1
ans = 1e10
for seed in seeds:
    res = search1(seed)
    ans = min(ans, res)
print(ans)


def search2(seed, r):
    """search a range, there are bugs I guess"""
    res = [(seed, r)]
    for m in maps:
        new_res = []
        for seed, r in res:
            s = seed
            found = False
            for src, dst, l in m:
                if s + r <= src or s >= src + l:
                    continue

                next_start = dst + s - src

                if s < src:
                    new_res.append((s, src - s))
                    r = r - (src - s)
                    s = src

                if s + r < src + l:
                    next_seed = (next_start, r)
                    found = True
                    new_res.append(next_seed)
                    break
                else:
                    next_r = src + l - s
                    next_seed = (next_start, next_r)
                    found = True
                    new_res.append(next_seed)

                    s = src + l
                    r = r - next_r
            if not found:
                new_res.append((seed, r))
        res = new_res
    ans = min([r[0] for r in res])
    return ans


# 2
ranges = [(seeds[i], seeds[i + 1]) for i in range(0, len(seeds), 2)]
ans = 1e10
for r, l in ranges:
    res = search2(r, l)
    ans = min(ans, res)
print(ans)

