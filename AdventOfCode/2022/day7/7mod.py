class File:
    def __init__(self, size: int, parent, type='dir'):
        self.size = size
        self.parent = parent
        self.type = type

    def update_total_size(self):
        p = self.parent
        while p is not None:
            p.size += self.size
            p = p.parent


data = open('input').read()
files = {'/': File(0, None)}
pwd = files['/']
pwd_list = ['']


data = data.split('$')[1:]
for cmd in data:
    match cmd.strip().splitlines():
        case ['cd /']:
            pwd = files['/']
            pwd_list = ['']
        case ['cd ..']:
            pwd = pwd.parent
            pwd_list.pop()
        case [cd_others] if cd_others.startswith('cd'):
            dir = cd_others.split()[1]
            pwd_list.append(dir)
            if dir not in files:
                files['/'.join(pwd_list)] = File(0, pwd)
            pwd = files['/'.join(pwd_list)]
        case ['ls', *outputs]:
            for line in outputs:
                size, name = line.split()
                abs_name = '/'.join(pwd_list + [name])
                if size == 'dir':
                    files[abs_name] = File(0, pwd)
                else:
                    files[abs_name] = File(int(size), pwd, 'file')
                    files[abs_name].update_total_size()
# part1
ans = 0
for f, n in files.items():
    if n.size <= 10_0000 and n.type == 'dir':
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
