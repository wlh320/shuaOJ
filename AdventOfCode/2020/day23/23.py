from copy import deepcopy
# data = "389125467"
data = "523764819"
data = [int(x) for x in data]
l = len(data)
p = 0

for _ in range(100):
    curr = data[p]
    pickups = [data[(p+x)%l] for x in range(1,4)]
    rem_max = max([x for x in data if x not in pickups])
    dest = curr - 1
    while dest > 0:
        if dest in data and dest not in pickups:
            break
        dest -= 1
    if dest <= 0:
        dest = rem_max
    new_data = deepcopy(data)
    for pickup in pickups:
        new_data.remove(pickup)
    destp = new_data.index(dest)
    new_data = new_data[0:destp+1] + pickups + new_data[destp+1:]
    data = new_data
    while data[p] != curr:
        data = data[1:] + [data[0]]
    p = (p + 1) % l

ans = ""
p = (data.index(1) + 1) % l 
while data[p] != 1:
    ans += str(data[p])
    p = (p+1) % l
print(ans)
