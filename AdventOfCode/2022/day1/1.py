lines = open('input').readlines()
ans = 0
k = 0
l = []
for line in lines:
    if line == "\n":
        ans = max(ans, k)
        l.append(k)
        k = 0
    else:
        x = int(line)
        k += x

print(ans)
l.sort(reverse=True)
print(l[0]+l[1]+l[2])
