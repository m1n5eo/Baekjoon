import sys
input = sys.stdin.readline

MOD = 1000000007

def init(start, end, node):
    if start == end:
        tree[node] = array[start]
        return tree[node]

    mid = (start + end) // 2
    tree[node] = init(start, mid, node*2) * init(mid+1, end, node*2+1) % MOD
    return tree[node]

def segment(start, end, node, left, right):
    if left <= start and end <= right:
        return tree[node]
    elif left > end or right < start:
        return 1
    
    mid = (start + end) // 2
    return segment(start, mid, node*2, left, right) * segment(mid+1, end, node*2+1, left, right) % MOD

def update(start, end, node, index, value):
    if index < start or end < index:
        return tree[node]
    elif start == end:
        tree[node] = value
        return tree[node]
    
    mid = (start + end) // 2
    tree[node] = update(start, mid, node*2, index, value) * update(mid+1, end, node*2+1, index, value) % MOD
    return tree[node]

n, m, k = map(int, input().split())
array = [0] + [int(input()) for _ in range(n)]
tree = [0 for _ in range((n+1)*4)]

init(1, n, 1)

for _ in range(m+k):
    mode, a, b = map(int, input().split())

    if mode == 1:
        update(1, n, 1, a, b)
        array[a] = b
    elif mode == 2:
        print(int(segment(1, n, 1, a, b)) % MOD)