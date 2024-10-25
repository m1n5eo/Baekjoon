import sys
input = sys.stdin.readline

def Find(x):
    if x != parent[x][0]:
        parent[x][0] = Find(parent[x][0])
    return parent[x][0]

def Union(x, y):
    x = Find(x)
    y = Find(y)

    if x > y:
        parent[x][0] = y
    else:
        parent[y][0] = x

def Same(x, y):
    x = Find(x)
    y = Find(y)

    return True if x == y else False

n, m = map(int, input().split())
parent = [[0, 0]]

for i in range(1, n+1):
    c = int(input())
    parent.append([i, c])

for _ in range(m):
    a, b = map(int, input().split())

    if Same(a, b) == False:
        temp = parent[Find(a)][1]+parent[Find(b)][1]
        Union(a, b)
        parent[Find(a)][1] = temp
    
    print(parent[Find(a)][1])