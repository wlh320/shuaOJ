blocks = open('input').read().split('\n\n')
shapes = []
areas = []
cases = []
for block in blocks:
    if 'x' not in block:
        shape = block.split('\n')[1:]
        shapes.append(shape)
        areas.append(sum(line.count('#') for line in shape))
    else:
        lines = block.splitlines()
        for line in lines:
            size, reqs = line.split(': ')
            size = list(map(int, size.split('x')))
            reqs = list(map(int, reqs.split(' ')))
            cases.append((size, reqs))

ans = 0
for size, reqs in cases:
    tot_area = size[0] * size[1]
    req_area = sum(a * b for a, b in zip(reqs, areas))
    if tot_area >= req_area:
        ans += 1
print(ans)
