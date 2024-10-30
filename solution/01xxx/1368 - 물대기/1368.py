import sys
input = sys.stdin.readline

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x = find(x)
    y = find(y)

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

def same(x, y):
    x = find(x)
    y = find(y)

    if x == y:
        return True
    else:
        return False

n = int(input())
parent = [i for i in range(n+1)]
mst = list()

for i in range(1, n+1):
    w = int(input())
    mst.append([0, i, w])

graph = [[0 for _ in range(n+1)]] + [[0] + list(map(int, input().split())) for _ in range(n)]

for i in range(1, n+1):
    for j in range(i+1, n+1):
        mst.append([i, j, graph[i][j]])
    
mst.sort(key=lambda mst: mst[2])

result = 0

for m in mst:
    if same(m[0], m[1]) == False:
        union(m[0], m[1])
        result += m[2]

print(result)