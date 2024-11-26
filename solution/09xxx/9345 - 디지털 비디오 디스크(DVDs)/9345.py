import sys
input = sys.stdin.readline

INF = 1e9

def init(start, end, node):
    if start == end:
        tree[node] = [book[start], book[start]]
        return tree[node]
    
    mid = (start + end) // 2

    a = init(start, mid, node*2)
    b = init(mid+1, end, node*2+1)

    tree[node] = [min(a[0], b[0]), max(a[1], b[1])]
    return tree[node]

def segment(start, end, node, left, right):
    if left <= start and end <= right:
        return tree[node]
    elif left > end or right < start:
        return [INF, -INF]
    
    mid = (start + end) // 2

    a = segment(start, mid, node*2, left, right)
    b = segment(mid+1, end, node*2+1, left, right)

    return [min(a[0], b[0]), max(a[1], b[1])]

def update(start, end, node, index, value):
    if index < start or end < index:
        return tree[node]
    elif start == end:
        tree[node] = [value, value]
        return tree[node]
    
    mid = (start + end) // 2
    
    a = update(start, mid, node*2, index, value)
    b = update(mid+1, end, node*2+1, index, value)

    tree[node] = [min(a[0], b[0]), max(a[1], b[1])]
    return tree[node]

tc = int(input())

for _ in range(tc):
    n, k = map(int, input().split())
    book = [i for i in range(n)]
    tree = [[0, 0] for _ in range(n*4)]
    result = list()

    init(0, n-1, 1)

    for _ in range(k):
        mode, a, b = map(int, input().split())

        if mode == 0:
            now = [book[a], book[b]]
            book[a], book[b] = book[b], book[a]
            update(0, n-1, 1, a, now[1])
            update(0, n-1, 1, b, now[0])
        elif mode == 1:
            small, big = segment(0, n-1, 1, a, b)
            result.append("YES" if small == a and big == b else "NO")

    for r in result:
        print(r)