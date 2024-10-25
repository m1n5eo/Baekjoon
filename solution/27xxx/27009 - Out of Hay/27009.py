import sys
input = sys.stdin.readline

def Find(x):
    if x != parent[x]:
        parent[x] = Find(parent[x])
    return parent[x]

def Union(x, y):
    x = Find(x)
    y = Find(y)

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

def Same(x, y):
    x = Find(x)
    y = Find(y)

    return True if x == y else False

n, m = map(int, input().split())
parent = list()
mst = list()

for i in range(n+1):
    parent.append(i)

for i in range(m):
    a, b, d = map(int, input().split())
    mst.append([a, b, d])

mst.sort(key=lambda mst: mst[2])

result = 0

for i in range(m):
    if(Same(mst[i][0], mst[i][1]) == False):
        Union(mst[i][0], mst[i][1])
        result = mst[i][2]

print(result)