import sys
input = sys.stdin.readline

def Find(x):
    if x != parent[x]:
        parent[x] = Find(parent[x])
    return parent[x]

def Union(x, y):
    x, y = Find(x), Find(y)

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

def Same(x, y):
    x, y = Find(x), Find(y)
    return True if x == y else False

tc = int(input())

for _ in range(tc):
    n = int(input())
    parent = [i for i in range(n+1)]
    telecom = [[0, 0, 0]]

    for i in range(1, n+1):
        x, y, r = map(int, input().split())
        telecom.append([x, y, r])
    
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            dist = (telecom[i][0]-telecom[j][0])*(telecom[i][0]-telecom[j][0]) + (telecom[i][1]-telecom[j][1])*(telecom[i][1]-telecom[j][1])

            if dist <= (telecom[i][2]+telecom[j][2])*(telecom[i][2]+telecom[j][2]):
                Union(i, j)

    count = 0
    
    for i in range(1, n+1):
        if not Same(0, i):
            Union(0, i)
            count += 1
    
    print(count)