line = open("input").readline().strip()
nums = list(map(int, list(line)))


disk = []
is_empty = False
id = 0
for x in nums:
    if is_empty:
        disk.extend(["."] * x)
    else:
        disk.extend([id] * x)
        id += 1
    is_empty = not is_empty

l = 0
r = len(disk) - 1

while l < r:
    while r >= 0 and disk[r] == ".":
        r -= 1
    while l < len(disk) and disk[l] != ".":
        l += 1
    if l < r:
        disk[l] = disk[r]
        disk[r] = "."

# 1
ans = 0
for i in range(len(disk)):
    if disk[i] == ".":
        break
    ans += disk[i] * i
print(ans)


# 2
EMP = -1
disk = []
is_empty = False
id = 0
for x in nums:
    if is_empty:
        disk.append((x, EMP))
    else:
        disk.append((x, id))
        id += 1
    is_empty = not is_empty


bound = len(disk) - 1
while True:
    r = bound
    while r >= 0 and disk[r][1] == EMP:
        r -= 1
    if r < 0:
        break
    l = 0
    sz, id = disk[r][0], disk[r][1]
    while l < len(disk) and (
        disk[l][1] != EMP or (disk[l][1] == EMP and disk[l][0] < sz)
    ):
        l += 1
    if l >= bound:
        bound = r - 1
        continue

    new_disk = disk.copy()
    new_disk[l] = (disk[r][0], disk[r][1])
    new_disk[r] = (sz, EMP)
    bound = r - 1
    if disk[l][0] > sz:
        new_disk.insert(l + 1, (disk[l][0] - sz, EMP))
    disk = new_disk

ans = 0
idx = 0
for sz, id in disk:
    if id != EMP:
        for i in range(sz):
            ans += idx * id
            idx += 1
    else:
        idx += sz
print(ans)
