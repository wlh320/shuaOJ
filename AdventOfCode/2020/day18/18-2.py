def calc(ops, nums):
    op = ops.pop()
    n2 = nums.pop()
    n1 = nums.pop()
    return n1 * n2 if op == '*' else n1 + n2 if op == '+' else None

# Shunting-Yard Algorithm
def solve(expr, pre_dict):
    expr = ''.join(expr.split())
    ops, nums = [], []
    for ch in expr:
        if str.isdigit(ch):
            nums.append(int(ch))
        elif ch == '(':
            ops.append('(')
        elif ch == ')':
            while ops[-1] != '(':
                x = calc(ops, nums)
                nums.append(x)
            ops.pop()
        elif ch in '+*':
            while ops and pre_dict[ops[-1]] >= pre_dict[ch]:
                x = calc(ops, nums)
                nums.append(x)
            ops.append(ch)
    while ops:
        x = calc(ops, nums)
        nums.append(x)
    return nums.pop()

lines = open('input').readlines()
sum1 = 0
sum2 = 0
pre_dict1 = {'*':2, '+':2, '(':1}
pre_dict2 = {'*':2, '+':3, '(':1}
for line in lines:
    sum1 += solve(line, pre_dict1)
    sum2 += solve(line, pre_dict2)
print(sum1)
print(sum2)
