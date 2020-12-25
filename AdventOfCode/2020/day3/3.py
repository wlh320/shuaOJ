from functools import reduce
f = open('input')
mat = []
for line in f.readlines():
    mat.append(line.strip())

def check(di, dj):
    i, j = 0, 0
    l, w = len(mat), len(mat[0])
    cnt = 0
    while i < l:
        if mat[i][j] == '#':
            cnt += 1
        j = (j + dj) % w
        i += di
    return cnt

# 1
print(check(1, 3))
# 2
ans = reduce(lambda x, y: x*y, [check(i, j) for i,j in zip([1,1,1,1,2], [1,3,5,7,1])])
print(ans)
