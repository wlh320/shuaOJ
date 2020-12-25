from functools import reduce
lines = open('input').readlines()
data = []
group = []
for line in lines:
    line = line.strip()
    if line == "":
        data.append(group)
        group = []
    else:
        group.append(set(line))
data.append(group)

ans = 0
for group in data:
    ans += len(reduce(lambda x, y: x | y, group))
print(ans)
ans = 0
for group in data:
    ans += len(reduce(lambda x, y: x & y, group))
print(ans)

