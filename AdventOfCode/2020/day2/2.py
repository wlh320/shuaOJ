import re
from collections import Counter
data = open('input').readlines()

r = re.compile(r'(\d+)-(\d+) ([a-z]): ([a-z]+)')
cnt = 0
for line in data:
    lo, hi, c, s = r.match(line).groups()
    lo, hi = int(lo), int(hi)
    if lo <= Counter(s)[c] <= hi:
        cnt += 1
print(cnt)

cnt = 0
for line in data:
    lo, hi, c, s = r.match(line).groups()
    lo, hi = int(lo), int(hi)
    if s[lo-1] == c and s[hi-1] != c:
        cnt += 1
    elif s[hi-1] == c and s[lo-1] != c:
        cnt += 1
print(cnt)
