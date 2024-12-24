lines = open("input").read().splitlines()
# lines = open("input1").read().splitlines()


def transform(x):

    def mix(a, b):
        return a ^ b

    def prune(x):
        return x % 16777216

    x = prune(mix(x * 64, x))
    x = prune(mix(int(x // 32), x))
    x = prune(mix(x * 2048, x))
    return x


def get_diff(x, n):
    s = [x % 10]
    for _ in range(n - 1):
        x = transform(x)
        s.append(x % 10)

    pd = [s[i] - s[i - 1] for i in range(1, len(s))]

    d = {}
    for i in range(3, len(pd)):
        t = tuple(pd[i - 3 : i + 1])
        if t not in d:
            d[t] = s[i + 1]
    return d


# 1
ans = 0
for line in lines:
    x = int(line)
    for _ in range(2000):
        x = transform(x)
    ans += x
print(ans)


# 2
def what_i_write_in_the_beginning_is_slow():
    diffs = []
    dd = set()

    for line in lines:
        x = int(line)
        d = get_diff(x, 2000)
        dd |= set(d.keys())
        diffs.append(d)

    ans = 0
    for x in dd:
        cand = sum(d.get(x, 0) for d in diffs)
        ans = max(ans, cand)
    print(ans)


def faster_but_still_brute_force():
    from collections import Counter

    diffs = Counter()
    for line in lines:
        x = int(line)
        d = get_diff(x, 2000)
        diffs += Counter(d)

    ans = max(diffs.values())
    print(ans)


faster_but_still_brute_force()
