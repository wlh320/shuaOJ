# rewrite after submit

data = open('input').read()
groups = data.split('\n\n')
ans = 0
elf = []
for group in groups:
    arr = list(map(int, group.splitlines()))
    elf.append(sum(arr))

elf.sort(reverse=True)
print(elf[0])
print(sum(elf[:3]))
