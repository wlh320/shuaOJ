import re

line = open("input").read().strip()

# 1
ans = 0
pattern = r"mul\((\d+),(\d+)\)"
matches = re.findall(pattern, line)
for x, y in matches:
    ans += int(x) * int(y)
print(ans)


# 2
ans = 0
line = re.sub(r"do\(\)", "mul(1,0)", line)
line = re.sub(r"don\'t\(\)", "mul(0,0)", line)
pattern = r"mul\((\d+),(\d+)\)"
matches = re.findall(pattern, line)

enabled = True
for x, y in matches:
    x, y = int(x), int(y)
    if (x, y) == (1, 0):
        enabled = True
    elif (x, y) == (0, 0):
        enabled = False

    if enabled:
        ans += x * y
print(ans)
