from collections import defaultdict

s = open("input").read().strip()
lines = s.splitlines()

# data processing
cards = []
for line in lines:
    id, numbers = line.split(": ")
    id = int(id.split()[1])
    win_num, my_num = numbers.split(" | ")
    win_num = list(map(int, win_num.split()))
    my_num = list(map(int, my_num.split()))
    cards.append((id, win_num, my_num))


def win_point(win_num, my_num):
    return len(set(win_num) & set(my_num))


# 1
ans = 0
for card in cards:
    id, win_num, my_num = card
    pnt = win_point(win_num, my_num)
    ans += int(pow(2, (pnt - 1)))
print(ans)

# 2
ans = 0
counts = defaultdict(int)
for card in cards:
    id, win_num, my_num = card
    counts[id] += 1
    pnt = win_point(win_num, my_num)
    for p in range(1, pnt + 1):
        counts[id + p] += counts[id]

ans = sum(counts.values())
print(ans)
