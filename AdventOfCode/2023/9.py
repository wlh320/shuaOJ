s = open("input").read().strip()
# s = open('input1').read().strip()


def predict(arr):
    arr_list = [arr.copy()]
    while any([x != 0 for x in arr]):
        new_arr = []
        n = len(arr)
        for i in range(1, n):
            new_arr.append(arr[i] - arr[i - 1])
        arr_list.append(new_arr)
        arr = new_arr

    ans1, ans2 = 0, 0
    for arr in arr_list[::-1]:
        ans1 = ans1 + arr[-1]
        ans2 = arr[0] - ans2
    return ans1, ans2


lines = s.splitlines()
ans1, ans2 = 0, 0
for line in lines:
    arr = list(map(int, line.split()))
    a1, a2 = predict(arr)
    ans1 += a1
    ans2 += a2

print(ans1)
print(ans2)
