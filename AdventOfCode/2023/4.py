s = open("input").read().strip()
# s = open('input1').read().strip()

groups = s.split("\n\n")


def process_seed(lines):
    seeds = lines.split(": ")[1]
    seeds = list(map(int, seeds.split()))
    return seeds


def process_map(lines):
    lines = lines.split("\n")[1:]
    m = []
    for line in lines:
        line = tuple(map(int, line.split()))
        dst, src, r = line
        m.append((src, dst, r))
    m.sort()
    return m


seeds = process_seed(groups[0])
maps = []
for g in groups[1:]:
    maps.append(process_map(g))

# 1
vals = []
for seed in seeds:
    val = seed
    for m in maps:
        for line in m:
            src, dst, r = line
            if val >= src and val < src + r:
                val = dst + (val - src)
                break
    vals.append(val)
print(min(vals))

# 2
vals = []
# seed range
seed_ranges = []
n = len(seeds)
for i in range(0, n, 2):
    s, r = seeds[i], seeds[i + 1]
    seed_ranges.append((s, r))

maps = maps[::-1]


print(min(vals))
