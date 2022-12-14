from itertools import zip_longest
from functools import cmp_to_key


def cmp(l, r) -> int:
    match l, r:
        case None, _: return 1
        case _, None: return -1
        case int(l), int(r): return 1 if l < r else 0 if l == r else -1
        case list(l), list(r):
            for a, b in zip_longest(l, r):
                ans = cmp(a, b)
                if ans != 0:
                    return ans
        case int(l), list(r): return cmp([l], r)
        case list(l), int(r): return cmp(l, [r])
    return 0


ans = 0
data = open('input').read().split('\n\n')
lst = []
for i, pair in enumerate(data):
    idx = i + 1
    pair = pair.split()
    l, r = eval(pair[0]), eval(pair[1])
    lst.append(l)
    lst.append(r)
    if cmp(l, r) == 1:
        ans += idx
print(ans)

# part2
sp1, sp2 = [[2]], [[6]]
lst.append(sp1)
lst.append(sp2)
lst.sort(key=cmp_to_key(cmp), reverse=True)
ans = (lst.index(sp1) + 1) * (lst.index(sp2) + 1)
print(ans)
