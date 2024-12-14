lines = open("input").read().strip()
cases = lines.split("\n\n")


def handle(case):
    case = str.replace(case, ",", "")
    case = case.split()

    a = [int(case[2].split("+")[1]), int(case[3].split("+")[1])]
    b = [int(case[6].split("+")[1]), int(case[7].split("+")[1])]
    t = [int(case[9].split("=")[1]), int(case[10].split("=")[1])]

    minc = 10**20
    for i in range(100):
        for j in range(100):
            coin = i * 3 + j * 1
            posx = a[0] * i + b[0] * j
            posy = a[1] * i + b[1] * j
            if posx == t[0] and posy == t[1]:
                minc = min(minc, coin)

    return 0 if minc == 10**20 else minc


# 1
ans = 0
for case in cases:
    ans += handle(case)
print(ans)


def handle2(case):
    case = str.replace(case, ",", "")
    case = case.split()

    a = [int(case[2].split("+")[1]), int(case[3].split("+")[1])]
    b = [int(case[6].split("+")[1]), int(case[7].split("+")[1])]
    t = [int(case[9].split("=")[1]), int(case[10].split("=")[1])]

    t[0] += 10000000000000
    t[1] += 10000000000000

    uu = t[1] * b[0] - b[1] * t[0]
    bb = a[1] * b[0] - b[1] * a[0]

    if uu % bb == 0:
        v1 = uu // bb
        v2 = (t[0] - a[0] * v1) // b[0]
        return 3 * v1 + v2
    else:
        return 0


# 2
ans = 0
for case in cases:
    ans += handle2(case)
print(ans)
