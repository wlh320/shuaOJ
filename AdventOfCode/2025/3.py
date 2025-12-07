lines = open("input").read()

ans = 0


def solve2(data, n):
    l = len(data)
    dp = [[0 for _ in range(n)] for _ in range(l)]

    for i in range(l):
        if i == 0:
            dp[i][0] = int(data[i])
        else:
            dp[i][0] = max(dp[i - 1][0], int(data[i]))

    for j in range(1, n):
        for i in range(l):
            if i < j:
                continue
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] * 10 + int(data[i]))

    return dp[-1][-1]


ans = 0
for line in lines.splitlines():
    ans += solve2(line, 2)
print(ans)

ans = 0
for line in lines.splitlines():
    ans += solve2(line, 12)
print(ans)
