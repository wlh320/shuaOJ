with open('input') as f:
    data = f.readlines()

data = map(int, data)
data = set(data)
for x in data:
    if (2020 - x) in data:
        print(x * (2020-x))

for x in data:
    for y in data:
        if x == y:
            continue
        if (2020 - x - y) in data:
            print(x*y*(2020-x-y))
