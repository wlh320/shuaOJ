data = open('input').read().splitlines()

def snafu_to_int(s):
    ans = 0
    for ch in s:
        ans *= 5
        if ch.isdecimal():
            ans += int(ch)
        elif ch == '=':
            ans -= 2
        elif ch == '-':
            ans -= 1
    return ans


def int_to_snafu(i):
    ans = ""
    base = 5
    while i != 0:
        d = (i % base)
        if d == 3:
            ans = '=' + ans
            i += base
            i = i // base
        elif d == 4:
            ans = '-' + ans
            i += base
            i = i // base
        else:
            ans = str(d) + ans
            i = i // base
    return ans


ans = 0
for line in data:
    ans += snafu_to_int(line.strip())

print(int_to_snafu(ans))

