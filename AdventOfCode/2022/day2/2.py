data = open('input').readlines()
ans = 0
for line in data:
    s = 0
    a, b = line.strip().split()
    d = {'X': 1, 'Y': 2, 'Z': 3}
    s += d[b]
    if b == 'X':
        if a == 'A':
            s += 3
        elif a == 'C':
            s += 6
    elif b == 'Y':
        if a == 'B':
            s += 3
        elif a == 'A':
            s += 6
    elif b == 'Z':
        if a == 'C':
            s += 3
        elif a == 'B':
            s += 6
    ans += s
print(ans)

# part2
ans = 0
for line in data:
    s = 0
    a, b = line.strip().split()
    d = {'X': 0, 'Y': 3, 'Z': 6}
    s += d[b]
    if b == 'X':  # lose
        da = {'A': 3, 'B': 1, 'C': 2}
        s += da[a]
    elif b == 'Y':  # draw
        da = {'A': 1, 'B': 2, 'C': 3}
        s += da[a]
    elif b == 'Z':  # win
        da = {'A': 2, 'B': 3, 'C': 1}
        s += da[a]
    ans += s
print(ans)
