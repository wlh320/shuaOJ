from functools import cache
s = open("input").read().strip()
# s = open("input1").read().strip()


def solve(s, nums):
    n, m = len(s), len(nums)

    @cache
    def dfs(i, j, curr):
        cnt = 0
        if i == n:
            if curr != 0 and j == m - 1 and curr == nums[j]:
                return 1
            elif curr == 0 and j >= m:
                return 1
            return 0

        if s[i] == '#':
            if j < m:
                cnt += dfs(i + 1, j, curr + 1)
        elif s[i] == '.':
            if curr == 0:
                cnt += dfs(i + 1, j, 0)
            elif j >= m or curr == nums[j]:
                cnt += dfs(i + 1, j + 1, 0)
        else:
            assert s[i] == '?'
            # choose #
            if j < m:
                cnt += dfs(i + 1, j, curr + 1)
            # choose .
            if curr == 0:
                cnt += dfs(i + 1, j, 0)
            elif j >= m or curr == nums[j]:
                cnt += dfs(i + 1, j + 1, 0)

        return cnt

    cnt = dfs(0, 0, 0)
    return cnt


# 1
lines = s.splitlines()
ans = 0
for line in lines:
    st, nums = line.split(" ")
    st = list(st.strip())
    nums = list(map(int, nums.strip().split(",")))
    cnt = solve(st, nums)
    ans += cnt
print(ans)

# 2
lines = s.splitlines()
ans = 0
for line in lines:
    st, nums = line.split(" ")
    st = [st] * 5
    nums = list(map(int, nums.strip().split(",")))
    st = list("?".join(st))
    nums = nums * 5
    cnt = solve(st, nums)
    ans += cnt
print(ans)
