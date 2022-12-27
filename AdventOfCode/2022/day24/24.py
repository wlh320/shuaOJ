from collections import defaultdict, deque

UP = (-1, 0)
DOWN = (1, 0)
LEFT = (0, -1)
RIGHT = (0, 1)
CH_MAP = {'^': UP, 'v': DOWN, '<': LEFT, '>': RIGHT}

data = open('input').read().splitlines()
R, C = len(data), len(data[0])
MP = defaultdict(list)
for i, line in enumerate(data):
    for j, ch in enumerate(line):
        if ch in CH_MAP:
            MP[(i, j)].append(CH_MAP[ch])


def move_blizzard(mp):
    new_mp = defaultdict(list)
    for (i, j), ds in mp.items():
        for d in ds:
            ni, nj = i + d[0], j + d[1]
            if ni <= 0: ni = R - 1 - 1
            if ni >= R - 1: ni = 1
            if nj <= 0: nj = C - 1 - 1
            if nj >= C - 1: nj = 1
            new_mp[(ni, nj)].append(d)
    return new_mp


MP_HIST = {}
MP_HIST[0] = MP

def find_path(start, end, start_time):
    q = deque([(start_time, start)])
    vis = set([(0, start)])
    while q:
        t, (i, j) = q.popleft()
        if t + 1 not in MP_HIST:
            MP_HIST[t + 1] = move_blizzard(MP_HIST[t])
        mp = MP_HIST[t + 1]
        if (i, j) == end:
            return t
        for ni, nj in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
            if (ni, nj) == end:
                q.append((t + 1, (ni, nj)))
                break
            if ni <= 0 or ni >= R - 1 or nj <= 0 or nj >= C - 1:
                continue
            if (ni, nj) in mp:
                continue
            if (t + 1, (ni, nj)) not in vis:
                q.append((t + 1, (ni, nj)))
                vis.add((t + 1, (ni, nj)))
        # wait
        if (t + 1, (i, j)) not in vis:
            if (i, j) not in mp:
                q.append((t + 1, (i, j)))
                vis.add((t + 1, (i, j)))

# part 1
START = (0, data[0].index('.'))
END = (R - 1, data[-1].index('.'))
t0 = find_path(START, END, 0)
print(t0)

# part 2
t1 = find_path(END, START, t0)
t2 = find_path(START, END, t1)
print(t2)
