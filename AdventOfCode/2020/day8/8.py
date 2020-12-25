lines = open('input').readlines()
pc = 0
value = 0
vis = set()
lines = [line.strip() for line in lines]
def one_run():
    pc = 0
    value = 0
    vis = set()
    while pc < len(lines):
        if pc in vis:
            break
        vis.add(pc)
        line = lines[pc]
        op, n = line.split(' ')
        if op == 'nop':
            pc += 1
        elif op == 'acc':
            value += int(n)
            pc += 1
        elif op == 'jmp':
            pc += int(n)
    return pc, value
# 1
pc, value = one_run()
print(value)
# 2
# just test jmp->nop and passed
for i in range(len(lines)):
    line = lines[i]
    op, n = line.split(' ')
    if op == 'jmp':
        lines[i] = 'nop +0'
        pc, value = one_run()
        if pc == len(lines):
            print(value)
        lines[i] = line
# test nop->jmp in vain
for i in range(len(lines)):
    line = lines[i]
    op, n = line.split(' ')
    if op == 'nop':
        lines[i] = f'jmp {n}'
        pc, value = one_run()
        if pc == len(lines):
            print(value)
        lines[i] = line

