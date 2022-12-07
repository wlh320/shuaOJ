data = open('input', 'r').readlines()
ans = 0
for line in data:
    l = len(line)
    a, b = line[:l//2], line[l//2:]
    c = set(a) & set(b)
    v = c.pop()
    if ord(v) >= ord('a') and ord(v) <= ord('z'):
        ans += ord(v) - ord('a') + 1
    elif ord(v) >= ord('A') and ord(v) <= ord('Z'):
        ans += ord(v) - ord('A') + 27
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
        v = s.pop()
        if ord(v) >= ord('a') and ord(v) <= ord('z'):
            ans += ord(v) - ord('a') + 1
        elif ord(v) >= ord('A') and ord(v) <= ord('Z'):
            ans += ord(v) - ord('A') + 27
        s = set([])
print(ans)
