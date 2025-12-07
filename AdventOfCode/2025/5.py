lines = open("input").read()

ranges, values = lines.split("\n\n", 1)

ranges = [list(map(int, rg.split("-"))) for rg in ranges.splitlines()]
values = list(map(int, values.splitlines()))

ans = 0
for v in values:
    for mi, ma in ranges:
        if mi <= v <= ma:
            ans += 1
            break
print(ans)


def merge(ranges):
    merged = []
    for mi, ma in ranges:
        if not merged:
            merged.append((mi, ma))
            continue
        last_mi, last_ma = merged[-1]
        if mi <= last_ma:
            merged[-1] = (last_mi, max(last_ma, ma))
        else:
            merged.append((mi, ma))
    return merged


ans2 = 0
merged_ranges = merge(sorted(ranges))
for mi, ma in merged_ranges:
    ans2 += ma - mi + 1
print(ans2)
