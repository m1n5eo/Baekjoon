import sys
input = sys.stdin.readline

def init(start, end, node):
    if start == end:
        tree[node] = array[start]
        return tree[node]
    
    mid = (start + end) // 2
    tree[node] = init(start, mid, node*2) ^ init(mid+1, end, node*2+1)
    return tree[node]

def updateLazy(start, end, node):
    if lazy[node] != 0:
        tree[node] ^= lazy[node] if (end - start + 1)%2 == 1 else 0
        if start != end:
            lazy[node*2] ^= lazy[node]
            lazy[node*2+1] ^= lazy[node]
        lazy[node] = 0

def update(start, end, node, left, right, value):
    updateLazy(start, end, node)

    if end < left or right < start:
        return
    elif left <= start and end <= right:
        tree[node] ^= value if (end - start + 1)%2 == 1 else 0
        if start != end:
            lazy[node*2] ^= value
            lazy[node*2+1] ^= value
        return
    
    mid = (start + end) // 2
    update(start, mid, node*2, left, right, value)
    update(mid+1, end, node*2+1, left, right, value)
    tree[node] = tree[node*2] ^ tree[node*2+1]

def segment(start, end, node, left, right):
    updateLazy(start, end, node)

    if end < left or right < start:
        return 0
    elif left <= start and end <= right:
        return tree[node]
    
    mid = (start + end) // 2
    return segment(start, mid, node*2, left, right) ^ segment(mid+1, end, node*2+1, left, right)

n = int(input())
array = list(map(int, input().split()))
tree = [0 for _ in range(n*4)]
lazy = [0 for _ in range(n*4)]
result = list()

init(0, n-1, 1)

for _ in range(int(input())):
    query = list(map(int, input().split()))

    if query[0] == 1:
        update(0, n-1, 1, query[1], query[2], query[3])
    elif query[0] == 2:
        result.append(segment(0, n-1, 1, query[1], query[2]))

for r in result:
    print(r)