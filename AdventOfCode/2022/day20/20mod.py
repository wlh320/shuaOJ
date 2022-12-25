from collections import deque
data = open('input').read().splitlines()
XS = []

for i, line in enumerate(data):
    x = int(line)
    XS.append((i, x))
    if x == 0:
        ZERO = (i, x)
L = len(XS)


def mix(xs, n):
    nums = deque(xs)
    origin = xs
    for _ in range(n):
        for i, x in origin:
            nums.rotate(-nums.index((i, x)))
            nums.popleft()
            nums.rotate(-x)
            nums.appendleft((i, x))
    return nums


# part1
nums = mix(XS, 1)
nums.rotate(-nums.index(ZERO))
ans = sum([nums[t % L][1] for t in [1000, 2000, 3000]])
print(ans)

# part2
KEY = 811589153
new_xs = [(i, x * KEY) for (i, x) in XS]
nums = mix(new_xs, 10)
nums.rotate(-nums.index(ZERO))
ans = sum([nums[t % L][1] for t in [1000, 2000, 3000]])
print(ans)
