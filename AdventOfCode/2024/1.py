lines = open("input").readlines()

l1, l2 = [], []
for line in lines:
    a, b = line.split()
    l1.append(int(a))
    l2.append(int(b))

# 1
ans = 0
l1.sort()
l2.sort()
for a, b in zip(l1, l2):
    ans += abs(a - b)
print(ans)

# 2
from collections import Counter

ans = 0
c = Counter(l2)
for x in l1:
    ans += x * c.get(x, 0)
print(ans)
