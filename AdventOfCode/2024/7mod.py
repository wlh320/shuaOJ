lines = open("input").readlines()
cases = []
for line in lines:
    tgt, nums = line.strip().split(":")
    tgt = int(tgt)
    nums = list(map(int, nums.split()))
    cases.append((tgt, nums))


def solve(tgt, nums, ops):

    def dfs(i, res):
        if res > tgt:
            return False
        if i == len(nums):
            return True if res == tgt else False

        ans = False
        for op in ops:
            ans = ans or dfs(i + 1, op(res, nums[i]))
        return ans

    return dfs(1, nums[0])


# 1
ans = 0
ops = [lambda a, b: a + b, lambda a, b: a * b]
for tgt, nums in cases:
    ans += tgt if solve(tgt, nums, ops) else 0
print(ans)


# 2
ans = 0
ops = [lambda a, b: a + b, lambda a, b: a * b, lambda a, b: int(str(a) + str(b))]
for tgt, nums in cases:
    ans += tgt if solve(tgt, nums, ops) else 0
print(ans)
