# lines = open('input2').readlines()
lines = open('input').readlines()
lines = list(map(lambda x: x.strip(), lines))


def solve(expr):
    if len(expr) == 0: return 0
    if len(expr) == 1 and str.isdigit(expr):
        return int(expr)

    if str.isdigit(expr[-1]):
        n1, op, n2 = solve(expr[:-2]), expr[-2], solve(expr[-1])
        return n1 * n2 if op == '*' else n1 + n2
    else:
        i = len(expr) - 1
        level = 0
        while i >= 0:
            ch = expr[i]
            if ch == ')':
                level += 1
            elif ch == '(':
                level -= 1
            if level == 0:
                break
            i -= 1
        if i == 0:
            return solve(expr[1:-1])
        else:
            n1, op, n2 = solve(expr[:i-1]), expr[i-1], solve(expr[i+1:-1])
        return n1 * n2 if op == '*' else n1 + n2

sum = 0
for line in lines:
    line = ''.join(line.split())
    ans = solve(line)
    sum += ans

print(sum)
# 我太菜了这么写不会搞第二问了
