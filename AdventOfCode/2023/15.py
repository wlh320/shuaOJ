from collections import defaultdict

input = open("input").read().strip()
# input = open("input1").read().strip()

# 1
ans = 0


def hash(s):
    h = 0
    for ch in s:
        h += ord(ch)
        h *= 17
        h = h % 256
    return h


for seg in input.split(","):
    ans += hash(seg)
print(ans)


# 2
ans = 0
boxes = defaultdict(list)
focals = defaultdict(int)
for seg in input.split(","):
    if "=" in seg:
        label, f = seg.split("=")
        box = hash(label)
        try:
            idx = boxes[box].index(label)
            focals[label] = int(f)
        except ValueError:
            boxes[box].append(label)
            focals[label] = int(f)
    else:
        assert seg[-1] == "-"
        label = seg[:-1]
        box = hash(label)
        try:
            idx = boxes[box].index(label)
            boxes[box].remove(label)
        except ValueError:
            pass

for box, content in boxes.items():
    for i, lens in enumerate(content):
        ans += (box + 1) * (i + 1) * focals[lens]
print(ans)
