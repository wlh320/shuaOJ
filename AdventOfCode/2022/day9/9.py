data = open('input').read().splitlines()

hr, hc = 0, 0
tr, tc = 0, 0
seen = set([])
seen.add((0, 0))
for line in data:
    line = line.strip().split()
    dir, n = line[0], int(line[1])
    for _ in range(n):
        # move head
        match dir:
            case 'U':
                hr -= 1
            case 'D':
                hr += 1
            case 'L':
                hc -= 1
            case 'R':
                hc += 1
        # move tail
        if hr > tr and abs(hr - tr) > 1:
            tr += 1
            if hc != tc:
                tc = hc
        elif hr < tr and abs(hr - tr) > 1:
            tr -= 1
            if hc != tc:
                tc = hc
        if hc > tc and abs(hc - tc) > 1:
            tc += 1
            if hr != tr:
                tr = hr
        elif hc < tc and abs(hc - tc) > 1:
            tc -= 1
            if hr != tr:
                tr = hr
        seen.add((tr, tc))
print(len(seen))


def move(hr, hc, tr, tc):
    # move tail
    if hr > tr and abs(hr - tr) > 1:
        tr += 1
        if hc > tc:
            tc += 1
        elif hc < tc:
            tc -= 1
        return hr, hc, tr, tc
    elif hr < tr and abs(hr - tr) > 1:
        tr -= 1
        if hc > tc:
            tc += 1
        elif hc < tc:
            tc -= 1
        return hr, hc, tr, tc

    if hc > tc and abs(hc - tc) > 1:
        tc += 1
        if hr > tr:
            tr += 1
        elif hr < tr:
            tr -= 1
        return hr, hc, tr, tc
    elif hc < tc and abs(hc - tc) > 1:
        tc -= 1
        if hr > tr:
            tr += 1
        elif hr < tr:
            tr -= 1
        return hr, hc, tr, tc

    return hr, hc, tr, tc


seen = set([])
seen.add((0, 0))
N = 10
rope = [[0, 0] for _ in range(N)]
for line in data:
    line = line.strip().split()
    dir, n = line[0], int(line[1])
    for _ in range(n):
        match dir:
            case 'U':
                rope[0][0] -= 1
            case 'D':
                rope[0][0] += 1
            case 'L':
                rope[0][1] -= 1
            case 'R':
                rope[0][1] += 1
        for s in range(1, N):
            hr, hc, tr, tc = move(
                rope[s-1][0], rope[s-1][1], rope[s][0], rope[s][1])
            rope[s - 1] = [hr, hc]
            rope[s] = [tr, tc]
            seen.add((rope[N-1][0], rope[N-1][1]))
print(len(seen))
