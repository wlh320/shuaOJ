from functools import reduce


def calc(op, cols):
    f = (lambda a, b: a * b) if op == "*" else (lambda a, b: a + b)
    return reduce(f, cols, 1 if op == "*" else 0)


# 1
lines = open("input").read().splitlines()
nums, ops = lines[:-1], lines[-1]
nums = [list(map(int, line.split())) for line in nums]
ops = ops.split()

n = len(nums[0])
for line in nums:
    assert len(line) == n

ans1 = 0
for i in range(n):
    xs = [x[i] for x in nums]
    ans1 += calc(ops[i], xs)
print(ans1)


# 2
lines = open("input").read().splitlines()
lines = [line + " " for line in lines]
m = len(lines)
n = len(lines[0])

ans2 = 0
op, cols = None, []
for j in range(n):
    col = "".join(lines[i][j] for i in range(m))
    if col == " " * m:
        ans2 += calc(op, cols)
        op, cols = None, []
        continue
    try:
        cols.append(int(col))
    except ValueError:
        op = col[-1]
        cols.append(int(col[:-1]))
print(ans2)
