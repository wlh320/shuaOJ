from functools import cache

line = open("input").readline()
line = line.split()
nums = list(map(int, line))


@cache
def dfs(i, x):
    if i == 0:
        return 1

    if x == 0:
        return dfs(i - 1, 1)

    s = str(x)
    if len(s) % 2 == 0:
        mid = len(s) // 2
        left = int(s[:mid])
        right = int(s[mid:])
        return dfs(i - 1, left) + dfs(i - 1, right)

    return dfs(i - 1, x * 2024)


# 1
N = 25
ans = 0
for x in nums:
    ans += dfs(N, x)
print(ans)

# 2
N = 75
ans = 0
for x in nums:
    ans += dfs(N, x)
print(ans)
