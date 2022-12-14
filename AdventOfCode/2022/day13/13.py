import functools
from itertools import zip_longest


def cmp(a, b):
    if a == b:
        return 0
    elif a < b:
        return 1
    else:
        return -1


def diff(l, r) -> int:
    # print(l, r)
    if l is None:
        return 1
    elif r is None:
        return -1
    if type(l) == int and type(r) == int:
        return cmp(l, r)
    elif type(l) == list and type(r) == list:
        for a, b in zip_longest(l, r):
            ans = diff(a, b)
            if ans == -1:
                return -1
            elif ans == 1:
                return 1
    elif type(l) == int and type(r) == list:
        return diff([l], r)
    elif type(l) == list and type(r) == int:
        return diff(l, [r])
    return 0


ans = 0
data = open('input').read().split('\n\n')
for i, pair in enumerate(data):
    idx = i + 1
    pair = pair.split()
    l, r = eval(pair[0]), eval(pair[1])
    if diff(l, r) == 1:
        ans += idx
    # print(f'{idx} {diff(l, r)}')
print(ans)

# part2
lst = []
data = open('input').read().splitlines()
for line in data:
    if line != '':
        x = eval(line)
        lst.append(x)
lst.append([[2]])
lst.append([[6]])
lst.sort(key=functools.cmp_to_key(diff), reverse=True)
k0 = lst.index([[2]]) + 1
k1 = lst.index([[6]]) + 1
print(k0 * k1)
