from collections import defaultdict
data = open('input').read().splitlines()
ELVES = set()
for i, line in enumerate(data):
    for j, ch in enumerate(line):
        if ch == '#':
            ELVES.add((i, j))

N = (-1, 0)
NE = (-1, 1)
NW = (-1, -1)
S = (1, 0)
SE = (1, 1)
SW = (1, -1)
W = (0, -1)
E = (0, 1)
RULES = [
        ((N, NE, NW), N),
        ((S, SE, SW), S),
        ((W, NW, SW), W),
        ((E, NE, SE), E)
]
ALLD = (N, NE, NW, S, SE, SW, W, E)

def move(r, elves):
    cand = defaultdict(int)
    count_not_move = 0
    for i, j in elves:
        if all((i+di, j+dj) not in elves for (di, dj) in ALLD):
            continue
        update = False
        for rule in range(r, r+4):
            checks, (ti, tj) = RULES[rule % len(RULES)]
            if all((i+di, j+dj) not in elves for (di, dj) in checks):
                cand[(i+ti, j+tj)] += 1
                break

    new_elves = set()
    for i, j in elves:
        if all((i+di, j+dj) not in elves for (di, dj) in ALLD):
            new_elves.add((i, j))
            count_not_move += 1
            continue
 
        update = False
        for rule in range(r, r+4):
            checks, (ti, tj) = RULES[rule % len(RULES)]
            if all((i+di, j+dj) not in elves for (di, dj) in checks):
                if cand[(i+ti, j+tj)] == 1:
                    if ((i+ti, j+tj)) not in elves:
                        new_elves.add((i+ti, j+tj))
                        update = True
                        break
                else:
                    break
        if not update:
            new_elves.add((i, j))
    elves = new_elves
    return elves, count_not_move

# part1
elves = ELVES.copy()
N = 10
for r in range(N):
    elves, _ = move(r, elves)

min_i, min_j, max_i, max_j = 10**10, 10**10, 0, 0
for i, j in elves:
    min_i, min_j = min(i, min_i), min(j, min_j)
    max_i, max_j = max(i, max_i), max(j, max_j)
ans = (max_i - min_i + 1) * (max_j - min_j + 1) - len(elves)
print(ans)

# part2
elves = ELVES.copy()
total = len(elves)
r = 0
while True:
    elves, count_not_move = move(r, elves)
    if total == count_not_move:
        break
    r += 1
print(r + 1)

