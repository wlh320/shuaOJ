def score(c):
    if ord(c) >= ord('a') and ord(c) <= ord('z'):
        return ord(c) - ord('a') + 1
    else:
        return ord(c) - ord('A') + 27


data = open('input', 'r').readlines()

# part1
ans = 0
for line in data:
    l = len(line)
    a, b = line[:l//2], line[l//2:]
    s = set(a) & set(b)
    ans += score(s.pop())
print(ans)

# part2
ans = 0
s = set([])
for i, line in enumerate(data):
    line = line.strip()
    if i % 3 == 0:
        s = set(line)
    else:
        s = s & set(line)
    if i % 3 == 2:
        ans += score(s.pop())
        s = set([])
print(ans)
