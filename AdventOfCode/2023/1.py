import re
lines = open('input').readlines()

# 1
ans = 0
for line in lines:
    line = line.strip()
    x = ''.join(list(filter(lambda x: x.isdigit(), line)))
    ans += int(x[0]) * 10 + int(x[-1])
print(ans)

# 2
N = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
ans = 0

for line in lines:
    line = line.strip()

    idxes = dict()
    for i, x in enumerate(N):
        all_pos = [a.start() for a in list(re.finditer(x, line))]
        if all_pos:
            idxes[i + 1] = (min(all_pos), max(all_pos))

    cand = []
    for i, ch in enumerate(line):
        if ch.isdigit():
            cand.append((i, int(ch)))

    first_index, first = cand[0][0], cand[0][1]
    last_index, last = cand[-1][0], cand[-1][1]
    for x in range(1, 10):
        if x in idxes and idxes[x][0] < first_index:
            first_index = idxes[x][0]
            first = x
        if x in idxes and idxes[x][1] > last_index:
            last_index = idxes[x][1]
            last = x

    ans += first * 10 + last

print(ans)
