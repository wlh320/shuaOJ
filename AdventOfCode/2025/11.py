from functools import lru_cache
from collections import defaultdict

lines = open("input").read().splitlines()

# Is G a DAG?
G = defaultdict(list)
for line in lines:
    src, dsts = line.split(": ")
    dsts = dsts.split(" ")
    G[src].extend(dsts)


def solve(start, target):

    @lru_cache
    def dfs(src):
        if src == target:
            return 1
        count = 0
        for dst in G[src]:
            count += dfs(dst)
        return count

    return dfs(start)


def solve2():
    s, a, b, t = "svr", "fft", "dac", "out"
    ans1 = solve(s, a) * solve(a, b) * solve(b, t)
    ans2 = solve(s, b) * solve(b, a) * solve(a, t)
    # If it is a DAG, ans1 == 0 or ans2 == 0
    assert (ans1 == 0 and ans2 != 0) or (ans1 != 0 and ans2 == 0)
    return ans1 + ans2


# 1
print(solve("you", "out"))
# 2
print(solve2())
