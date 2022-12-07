class Node:
    def __init__(self, size: int, parent, type='dir'):
        self.size = size
        self.parent = parent
        self.type = type


data = open('input').read()
# data = open('input1').read()
ans = 0
files = {'/': Node(0, None)}
pwd = files['/']
pwd_list = ['/']

data = data.split('$')[1:]
for cmd in data:
    cmd = cmd.strip().splitlines()
    cmd, outputs = cmd[0].split(), cmd[1:]
    if cmd[0] == 'cd':
        if cmd[1] == '/':
            pwd = files['/']
            pwd_list = ['/']
        elif cmd[1] == '..':
            pwd = pwd.parent
            pwd_list.pop()
        elif cmd[1] in files:
            pwd_list.append(cmd[1])
            name = '/'.join(pwd_list)
            pwd = files[name]
        else:
            pwd_list.append(cmd[1])
            name = '/'.join(pwd_list)
            files[name] = Node(0, pwd)
            pwd = files[name]
    elif cmd[0] == 'ls':
        for output in outputs:
            output = output.split()
            size, name = output
            if size == 'dir':
                abs_name = '/'.join(pwd_list + [name])
                files[abs_name] = Node(0, pwd)
            else:
                size = int(size)
                abs_name = '/'.join(pwd_list + [name])
                files[abs_name] = Node(0, pwd, 'file')
                p = files[abs_name]
                while p != None:
                    p.size += size
                    p = p.parent
# part1
ans = 0
for f, n in files.items():
    if n.size <= 100000 and n.type == 'dir':
        ans += n.size
print(ans)

# part2
total = files['/'].size
need_to_delete = total - 4000_0000
cand = []
for f, n in files.items():
    if n.size >= need_to_delete and n.type == 'dir':
        cand.append((n.size, f))
cand.sort()
print(cand[0][0])
