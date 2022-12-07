import re
data = open('input').readlines()
PTN = re.compile(r'(\d+)-(\d+),(\d+)-(\d+)')
# part 1
ans = 0
for line in data:
    x = re.findall(PTN, line)[0]
    min_a, max_a, min_b, max_b = map(int, x)
    if min_a >= min_b and max_a <= max_b:
        ans += 1
    elif min_b >= min_a and max_b <= max_a:
        ans += 1
print(ans)

# part 2
ans = 0
for line in data:
    x = re.findall(PTN, line)[0]
    min_a, max_a, min_b, max_b = map(int, x)
    if not (max_a < min_b or min_a > max_b):
        ans += 1
print(ans)
