"""
Coin sums
How many different ways can £2 be made using any number of coins?
"""

coins = [1, 2, 5, 10, 20, 50, 100, 200]
cnt = 0


def dfs(i, left):
    global cnt
    if left == 0:
        cnt += 1
        return
    if left < 0 or i >= len(coins):
        return
    j = 0
    while left - j * coins[i] >= 0:
        dfs(i + 1, left - coins[i] * j)  # take j * this coin(s)
        j += 1


def do_dp():
    dp = [1] + [0] * 205
    for i in range(0, len(coins)):
        for j in range(coins[i], 201):
            dp[j] += dp[j-coins[i]]
    return dp[200]


# dfs(0, 200)
# print(cnt)
print(do_dp())  # dfs is naive! dp is double-plus-good!
