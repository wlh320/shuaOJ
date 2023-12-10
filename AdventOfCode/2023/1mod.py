lines = open('input').readlines()

# 1
ans = 0
for line in lines:
    line = line.strip()
    x = ''.join(list(filter(lambda x: x.isdigit(), line)))
    ans += int(x[0]) * 10 + int(x[-1])
print(ans)

# 2
NUM = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
ans = 0

for line in lines:
    line = line.strip()

    digits = []
    for i, ch in enumerate(line):
        if ch.isdigit():
            digits.append(int(ch))
        else:
            for j, x in enumerate(NUM):
                if line[i:].startswith(x):
                    digits.append(j + 1)

    ans += digits[0] * 10 + digits[-1]

print(ans)
