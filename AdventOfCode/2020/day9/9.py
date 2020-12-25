lines = open('input').readlines()
lines = list(map(lambda x: int(x.strip()), lines))

def is_valid(x, prev_arr):
    for i, prev in enumerate(prev_arr):
        if x - prev in prev_arr[:i] + prev_arr[i+1:]:
            return True
    return False

ans1 = 0
for i in range(25, len(lines)):
    if not is_valid(lines[i], lines[i-25:i]):
        ans1 = lines[i]
        break
print(ans1)

accu = [0]
for x in lines:
    accu.append(accu[-1]+x)

for i in range(len(lines)):
    for j in range(i, len(lines)):
        if accu[j] - accu[i] == ans1 and lines[i] != ans1:
            target = lines[i:j]
            print(min(target) + max(target))
            exit(0)
