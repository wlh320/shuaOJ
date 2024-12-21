lines = open("input").read()

s1, s2 = lines.split("\n\n")
ptns = set(s1.split(", "))
designs = s2.splitlines()


def can_design(ptns, tgt):
    l = len(tgt)
    dp = [True] + [False] * l

    for i in range(l):
        for j in range(0, i + 1):
            if tgt[j : i + 1] in ptns and dp[j]:
                dp[i + 1] = True
                break
    return dp[l] == True


def design_cnt(ptns, tgt):
    l = len(tgt)
    dp = [1] + [0] * l

    for i in range(l):
        for j in range(0, i + 1):
            if tgt[j : i + 1] in ptns:
                dp[i + 1] += dp[j]
    return dp[l]


# 1
ans = 0
for design in designs:
    if can_design(ptns, design):
        ans += 1
print(ans)

# 2
ans = 0
for design in designs:
    ans += design_cnt(ptns, design)
print(ans)
