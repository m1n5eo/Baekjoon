import sys
input = sys.stdin.readline

MAX = 24*60*60

def updateLazy(start, end, node):
    if lazy[node] != 0:
        tree[node] += (end - start + 1) * lazy[node]
        if start != end:
            lazy[node*2] += lazy[node]
            lazy[node*2+1] += lazy[node]
        lazy[node] = 0

def update(start, end, node, left, right):
    updateLazy(start, end, node)

    if right < start or end < left:
        return
    elif left <= start and end <= right:
        tree[node] += (end - start + 1)
        if start != end:
            lazy[node*2] += 1
            lazy[node*2+1] += 1
        return
    
    mid = (start + end) // 2
    update(start, mid, node*2, left, right)
    update(mid+1, end, node*2+1, left, right)
    tree[node] = tree[node*2] + tree[node*2+1]

def segment(start, end, node, left, right):
    updateLazy(start, end, node)

    if end < left or right < start:
        return 0
    elif left <= start and end <= right:
        return tree[node]
    
    mid = (start + end) // 2
    return segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right)

tree = [0 for _ in range(MAX*4)]
lazy = [0 for _ in range(MAX*4)]
result = list()

for _ in range(int(input())):
    start, temp, end = map(str, input().split())

    h, m, s = start.split(":")
    time1 = int(h)*60*60 + int(m)*60 + int(s)

    h, m, s = end.split(":")
    time2 = int(h)*60*60 + int(m)*60 + int(s)

    if time1 <= time2:
        update(0, MAX-1, 1, time1, time2)
    else:
        update(0, MAX-1, 1, time1, MAX-1)
        update(0, MAX-1, 1, 0, time2)

for _ in range(int(input())):
    start, temp, end = map(str, input().split())

    h, m, s = start.split(":")
    time1 = int(h)*60*60 + int(m)*60 + int(s)

    h, m, s = end.split(":")
    time2 = int(h)*60*60 + int(m)*60 + int(s)

    if time1 <= time2:
        result.append(segment(0, MAX-1, 1, time1, time2) / (time2 - time1 + 1))
    else:
        first = segment(0, MAX-1, 1, time1, MAX-1)
        second = segment(0, MAX-1, 1, 0, time2)
        result.append((first + second) / (MAX - time1 + time2 + 1))

for r in result:
    print('%.10f' % r)