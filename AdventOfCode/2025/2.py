line = open("input").read().strip()
to_int_pair = lambda x: list(map(int, x.split("-")))
ranges = list(map(to_int_pair, line.split(",")))


def count(s):
    return s[: len(s) // 2] == s[len(s) // 2 :]


def is_valid(s, r):
    return not any(s[i : i + r] != s[0:r] for i in range(r, len(s), r))


def count2(s):
    for r in range(1, len(s) // 2 + 1):
        if len(s) % r != 0:
            continue
        if is_valid(s, r):
            return True
    return False


ans1 = ans2 = 0
for rg in ranges:
    for x in range(rg[0], rg[1] + 1):
        s = str(x)
        if count(s):
            ans1 += x
        if count2(s):
            ans2 += x
print(ans1)
print(ans2)
