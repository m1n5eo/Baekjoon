import sys
input = sys.stdin.readline

def init(start, end, node):
    if start == end:
        tree[node] = array[start]
        return tree[node]
    
    mid = (start + end) // 2
    tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1)
    return tree[node]

def updateLazy(start, end, node):
    if lazy[node] != 0:
        tree[node] = tree[node] + (end - start + 1) * lazy[node]
        if start != end:
            lazy[node*2] += lazy[node]
            lazy[node*2+1] += lazy[node]
        lazy[node] = 0

def update(start, end, node, left, right, value):
    updateLazy(start, end, node) 

    if right < start or end < left:
        return
    elif left <= start and end <= right:
        tree[node] = tree[node] + (end - start + 1) * value
        if start != end:
            lazy[node*2] += value
            lazy[node*2+1] += value 
        return
    
    mid = (start + end) // 2
    update(start, mid, node*2, left, right, value)
    update(mid+1, end, node*2+1, left, right, value)
    tree[node] = tree[node*2] + tree[node*2+1]

def segment(start, end, node, index):
    updateLazy(start, end, node)

    if end < index or index < start:
        return 0
    elif index <= start and end <= index:
        return tree[node]
    
    mid = (start + end) // 2
    return segment(start, mid, node*2, index) + segment(mid+1, end, node*2+1, index)

n = int(input())
array = [0] + list(map(int, input().split()))
tree = [0 for _ in range((n+1)*4)]
lazy = [0 for _ in range((n+1)*4)]
result = list()

init(1, n, 1)

for _ in range(int(input())):
    query = list(map(int, input().split()))

    if query[0] == 1:
        update(1, n, 1, query[1], query[2], query[3])
    elif query[0] == 2:
        result.append(segment(1, n, 1, query[1]))

for r in result:
    print(r)