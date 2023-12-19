import re
from copy import deepcopy

input = open("input").read().strip()
# input = open("input1").read().strip()

lines = input.splitlines()
rules, parts = input.split("\n\n")
rules = rules.strip().splitlines()
parts = parts.strip().splitlines()

workflows = dict()
for s in rules:
    name, flow = s.split("{")
    flow = flow[:-1].split(",")
    workflows[name] = flow


def parse(rule, x, m, a, s):
    for r in rule:
        if ":" in r:
            left, res = r.split(":")
            if eval(left) != True:
                continue
            if res in ["A", "R"]:
                return res
            else:
                return parse(workflows[res], x, m, a, s)
        else:
            if r in ["A", "R"]:
                return r
            else:
                return parse(workflows[r], x, m, a, s)
    assert False


# 1
ans = 0
for p in parts:
    xs = re.findall(r"(\d+)", p)
    x, m, a, s = list(map(int, xs))
    res = parse(workflows["in"], x, m, a, s)
    if res == "A":
        ans += x + m + a + s
print(ans)


# 2
def check_invalid(limits: dict):
    for _, (x0, x1) in limits.items():
        if x0 > x1:
            return True
    return False


def split_limit(sign, n, limit):
    lim_down, lim_up = limit
    if sign == ">":
        valid = (n + 1, lim_up)
        invalid = (lim_down, n)
    else:
        valid = (lim_down, n - 1)
        invalid = (n, lim_up)
    return valid, invalid


def dfs(rule, limits) -> int:
    # reject invalid limits
    if check_invalid(limits):
        return 0

    if rule == "A":
        ans = 1
        for _, (x0, x1) in limits.items():
            ans *= x1 - x0 + 1
        return ans
    elif rule == "R":
        return 0

    workflow = workflows[rule]
    ans = 0
    for r in workflow:
        if check_invalid(limits):
            return ans

        # need recursion
        if ":" in r:
            left, res = r.split(":")
            id, sign, n = left[0], left[1], int(left[2:])
            limit = limits[id]
            valid, invalid = split_limit(sign, n, limit)

            # if valid
            new_limits = deepcopy(limits)
            new_limits[id] = valid
            ans += dfs(res, new_limits)

            # if invalid, next rule
            new_lim = invalid
            limits[id] = new_lim
        else:
            ans += dfs(r, deepcopy(limits))
    return ans


limits = {"x": (1, 4000), "m": (1, 4000), "a": (1, 4000), "s": (1, 4000)}
ans = dfs("in", limits)
print(ans)
