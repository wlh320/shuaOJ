data = open('input')
def cal(s):
    row, col = 0, 0
    lo = 0
    hi = 127
    for x in s[:7]:
        mid = lo + (hi - lo) // 2
        if x == 'F':
            hi = mid
        elif x == 'B':
            lo = mid
    row = hi
    lo = 0
    hi = 7
    for x in s[7:]:
        mid = lo + (hi - lo) // 2
        if x == 'R':
            lo = mid
        elif x == 'L':
            hi = mid
    col = hi
    return row * 8 + col

xs = []
for line in data.readlines():
    xs.append(cal(line))
print(max(xs))

for i in range(127):
    for j in range(7):
        id = i * 8 + j
        if id not in xs and (id+1) in xs and (id-1) in xs:
            print(i * 8 + j)
