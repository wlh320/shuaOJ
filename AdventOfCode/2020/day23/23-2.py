from copy import deepcopy
N = 100_0000
M = 1000_0000
# data = "389125467"
data = "523764819"
data = [int(x) for x in data]
data.extend(range(10, N+1))

class Node:
    def __init__(self, val=0):
        self.val = val
        self.next = None

table = {}

for x in data:
    table[x] = Node(x)
for i, _ in enumerate(data):
    table[data[i]].next = table[data[(i+1)%len(data)]]

curr = table[data[0]]
for _ in range(M):
    # pickups
    pickups = [curr.next, curr.next.next, curr.next.next.next]
    curr.next = pickups[-1].next
    # dest
    invalid_vals = [curr.val, *[x.val for x in pickups]]
    dval = curr.val
    while dval in invalid_vals:
        dval -= 1
    if dval <= 0:
        dval = N
    
    dest = table[dval]
    pickups[-1].next = dest.next
    dest.next = pickups[0]
    curr = curr.next

curr = table[1]
ans = table[1].next.val * table[1].next.next.val
print(ans)
