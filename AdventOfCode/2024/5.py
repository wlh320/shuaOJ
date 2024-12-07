from collections import defaultdict
from functools import cmp_to_key

lines = open("input").read().strip()
rules, pages = lines.split("\n\n")
rules = rules.splitlines()
pages = pages.splitlines()
pages = [list(map(int, page.split(","))) for page in pages]

orders = defaultdict(set)
for rule in rules:
    r1, r2 = rule.split("|")
    r1, r2 = int(r1), int(r2)
    orders[r1].add(r2)


def is_ok(page):
    for i in range(1, len(page)):
        for j in range(i):
            if page[i] not in orders[page[j]]:
                return False
    return True


# 1
ans = 0
for page in pages:
    if is_ok(page):
        ans += page[len(page) // 2]
print(ans)


# 2
def cmp(a, b):
    if b in orders[a]:
        return -1
    elif a in orders[b]:
        return 1
    return 0


ans = 0
for page in pages:
    if not is_ok(page):
        page.sort(key=cmp_to_key(cmp))
        ans += page[len(page) // 2]
print(ans)
