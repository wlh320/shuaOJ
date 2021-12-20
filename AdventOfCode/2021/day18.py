from functools import reduce
from copy import deepcopy
import math


class Fish:
    def __init__(self, data=None):
        self.val, self.left, self.right = None, None, None
        if type(data) is int:
            self.val = data
        elif type(data) is list:
            self.left, self.right = Fish(data[0]), Fish(data[1])
        elif type(data) is Fish:
            self.left, self.right = data.left, data.right

    def __repr__(self) -> str:
        if self.val is not None:
            return str(self.val)
        return f'[{self.left},{self.right}]'

    def sum(self) -> int:
        if self.val is not None:
            return self.val
        return 3 * self.left.sum() + 2 * self.right.sum()


def add(a: Fish, b: Fish) -> Fish:
    c = Fish([deepcopy(a), deepcopy(b)])
    while True:
        flag = explode(c)
        if flag:
            continue
        flag = split(c)
        if not flag:
            break
    return c


def get_leaves(a: Fish):
    if a.val is not None:
        yield a
    if a.left:
        yield from get_leaves(a.left)
    if a.right:
        yield from get_leaves(a.right)


def get_first_l4_node(a: Fish, level) -> Fish | None:
    if level == 4 and a.val is None:
        return a
    if a.left:
        l = get_first_l4_node(a.left, level + 1)
        if l is not None:
            return l
    if a.right:
        r = get_first_l4_node(a.right, level + 1)
        return r
    return None


def explode(a: Fish) -> bool:
    node = get_first_l4_node(a, 0)
    if node is None:
        return False
    leaves = list(get_leaves(a))
    l_idx = leaves.index(node.left)
    r_idx = l_idx + 1
    if l_idx > 0:
        leaves[l_idx - 1].val += node.left.val
    if r_idx + 1 < len(leaves):
        leaves[r_idx + 1].val += node.right.val
    node.val, node.left, node.right = 0, None, None
    return True


def split(a: Fish) -> bool:
    flag = False
    for leaf in get_leaves(a):
        if leaf.val > 9:
            leaf.left = Fish(leaf.val // 2)
            leaf.right = Fish(int(math.ceil(leaf.val / 2)))
            leaf.val = None
            flag = True
            break
    return flag


content = open('input').readlines()
l = []
for line in content:
    x = eval(line)
    f = Fish(x)
    l.append(f)
# 1
ans = reduce(lambda x, y: add(x, y), l)
print(ans.sum())

# 2
sums = []
for a in l:
    for b in l:
        if a != b:
            sums.append(add(a, b).sum())
            sums.append(add(b, a).sum())
print(max(sums))
