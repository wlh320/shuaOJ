input = open("input").read().strip()
# input = open("input1").read().strip()

groups = input.split("\n\n")

check1 = lambda xs: all(x == 0 for x in xs)
check2 = lambda xs: 1 in xs and sum(xs) == 1


def solve(grid, check):
    n, m = len(grid), len(grid[0])
    # vertical
    for s in range(m - 1):
        diffs = []
        for i in range(n):
            diff = 0
            lo, hi = s, s + 1
            while lo >= 0 and hi < m:
                if grid[i][lo] != grid[i][hi]:
                    diff += 1
                lo -= 1
                hi += 1
            diffs.append(diff)
        if check(diffs):
            return s + 1

    # horizontal
    for s in range(n - 1):
        diffs = []
        for j in range(m):
            diff = 0
            lo, hi = s, s + 1
            while lo >= 0 and hi < n:
                if grid[lo][j] != grid[hi][j]:
                    diff += 1
                lo -= 1
                hi += 1
            diffs.append(diff)
        if check(diffs):
            return (s + 1) * 100
    return 0


ans1 = 0
ans2 = 0
for g in groups:
    grid = g.splitlines()
    ans1 += solve(grid, check1)
    ans2 += solve(grid, check2)
print(ans1)
print(ans2)
