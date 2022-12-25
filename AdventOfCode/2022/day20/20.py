data = open('input').read().splitlines()
xs = []

for i, line in enumerate(data):
    x = int(line)
    xs.append((i, x))
    if x == 0:
        ZERO = (i, 0)
l = len(xs)


def mix(xs, n):
    nums = xs[:]
    for _ in range(n):
        for i, x in xs:
            if x == 0:
                continue

            # compute index
            old_idx = nums.index((i, x))
            new_idx = (old_idx + x) % (l - 1)

            # create new array
            nums = nums[:old_idx] + nums[old_idx+1:]
            if new_idx == 0:
                nums.append((i, x))
            else:
                nums.insert(new_idx, (i, x))
    return nums


nums = mix(xs, 1)
# part1
pos0 = nums.index(ZERO)
ans = sum([nums[(pos0 + t) % l][1] for t in [1000, 2000, 3000]])
print(ans)

# part2
KEY = 811589153
new_xs = [(i, x * KEY) for (i, x) in xs]
nums = mix(new_xs, 10)
pos0 = nums.index(ZERO)
ans = sum([nums[(pos0 + t) % l][1] for t in [1000, 2000, 3000]])
print(ans)
