lines = open("input").readlines()


def solve(tgt, nums):
    l = len(nums)

    def dfs(i, res):
        if res > tgt:
            return False
        if i == l:
            if res == tgt:
                return True
            else:
                return False

        if i + 1 >= l:
            return dfs(i + 1, res)
        else:
            ans = dfs(i + 1, res + nums[i + 1]) or dfs(i + 1, res * nums[i + 1])
            return ans

    if dfs(0, nums[0]):
        return tgt
    else:
        return 0


# 1
ans = 0
for line in lines:
    tgt, nums = line.strip().split(":")
    tgt = int(tgt)
    nums = list(map(int, nums.split()))
    ans += solve(tgt, nums)
print(ans)


def solve2(tgt, nums):
    l = len(nums)

    def dfs(i, res):
        if res > tgt:
            return False
        if i == l:
            if res == tgt:
                return True
            else:
                return False

        if i + 1 >= l:
            return dfs(i + 1, res)
        else:
            ans1 = dfs(i + 1, res + nums[i + 1])
            ans2 = dfs(i + 1, res * nums[i + 1])
            ans3 = dfs(i + 1, int(str(res) + str(nums[i + 1])))
            return ans1 or ans2 or ans3

    if dfs(0, nums[0]):
        return tgt
    else:
        return 0


# 2
ans = 0
for line in lines:
    tgt, nums = line.strip().split(":")
    tgt = int(tgt)
    nums = list(map(int, nums.split()))
    ans += solve2(tgt, nums)
print(ans)
