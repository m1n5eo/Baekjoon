import sys
input = sys.stdin.readline

def init(start, end, node):
    if start == end:
        tree[node] = v[start]
        return tree[node]
    
    mid = (start+end)//2
    tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1)
    return tree[node]

def segment(start, end, node, left, right):
    if end < left or right < start:
        return 0
    elif left <= start and end <= right:
        return tree[node]
    
    mid = (start+end)//2
    return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right)

def update(start, end, node, index, value):
    if index < start or end < index:
        return tree[node]
    elif start == end:
        tree[node] = value
        return tree[node]
    
    mid = (start+end)//2
    tree[node] = update(start, mid, node*2, index, value) + update(mid+1, end, node*2+1, index, value)
    return tree[node]

n, m, k = map(int, input().split())

v = [0]*(n+1)
tree = [0]*(n+1)*4

for i in range(1, n+1):
    v[i] = int(input())

init(1, n, 1)

for i in range(m+k):
    mode, a, b = map(int, input().split())

    if mode == 1:
        update(1, n, 1, a, b)
        v[a] = b
    elif mode == 2:
        print(segment(1, n, 1, a, b))