lines = open('input').readlines()
adapters = list(map(lambda x: int(x.strip()), lines))
adapters.sort()

# 1
x = 0
ds = [0, 0, 0, 1]
for adapter in adapters:
    ds[adapter - x] += 1
    x = adapter
print(ds[1] * ds[3])

# 2
target = max(adapters) + 3
dp = [0] * (target+1)
dp[0] = 1
adapters.append(target)
get = lambda x: 0 if x < 0 else dp[x]
for adapter in adapters:
    dp[adapter] = get(adapter-1) + get(adapter-2) + get(adapter-3)
print(dp[target])
