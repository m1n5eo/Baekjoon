import sys
input = sys.stdin.readline

def init(start, end, node):
    if start == end:
        tree[node] = array[start]
        return tree[node]
    
    mid = (start + end) // 2
    tree[node] = max(init(start, mid, node*2), init(mid+1, end, node*2+1))
    return tree[node]

def segment(start, end, node, left, right):
    if end < left or right < start:
        return 0
    elif left <= start and end <= right:
        return tree[node]

    mid = (start + end) // 2
    return max(segment(start, mid, node*2, left, right), segment(mid+1, end, node*2+1, left, right))

result = list()

for _ in range(int(input())):
    n = int(input())
    array = list(map(int, input().split()))

    tree = [0 for _ in range(n*4)]
    d = dict()

    init(0, n-1, 1)
    
    for i in range(len(array)):
        if array[i] not in d.keys():
            d[array[i]] = [i, i]
        elif array[i] in d.keys():
            d[array[i]][1] = i
    
    stop = True
    
    for key, value in d.items():
        if key != segment(0, n-1, 1, value[0], value[1]):
            stop = False
            break
    
    result.append("Yes" if stop == True else "No")

for r in result:
    print(r)