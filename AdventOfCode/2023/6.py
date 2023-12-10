s = open("input").read().strip()
# s = open('input1').read().strip()

lines = s.splitlines()

times = [54, 94, 65, 92]
distances = [302, 1476, 1029, 1404]

# times = [7, 15, 30]
# distances = [9, 40, 200]

# 1
ways = []
for t, record in zip(times, distances):
    way = 0
    for i in range(t):
        speed = i
        dis = (t - i) * i
        if dis > record:
            way += 1
    ways.append(way)

ans = 1
for way in ways:
    ans *= way
print(ans)


# 2
time = int("".join(str(t) for t in times))
record = int("".join(str(d) for d in distances))

l = 0
r = time // 2 + 1
while l < r:
    mid = l + (r - l) // 2
    dis = (time - mid) * mid
    if dis > record:
        r = mid
    elif dis < record:
        l = mid + 1
    elif dis == record:
        r = mid
l_bound = l

l = time // 2
r = time + 1
while l < r:
    mid = l + (r - l) // 2
    dis = (time - mid) * mid
    if dis < record:
        r = mid
    elif dis > record:
        l = mid + 1
    elif dis == record:
        l = mid + 1
r_bound = r - 1

ans = r_bound - l_bound + 1
print(ans)
