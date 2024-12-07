lines = open("input").readlines()


def is_safe(arr):
    # condition 1
    a1 = sorted(arr)
    a2 = sorted(arr, reverse=True)
    if arr != a1 and arr != a2:
        return False
    # condition 2
    for i in range(1, len(arr)):
        diff = abs(arr[i] - arr[i - 1])
        if not (1 <= diff <= 3):
            return False
    return True


# 1
ans = 0
for line in lines:
    arr = list(map(int, line.split()))
    if is_safe(arr):
        ans += 1
print(ans)


# 2
ans = 0
for line in lines:
    arr = list(map(int, line.split()))
    if is_safe(arr):
        ans += 1
        continue

    for j in range(len(arr)):
        new_arr = arr[0:j] + arr[j + 1 :]
        if is_safe(new_arr):
            ans += 1
            break
print(ans)
