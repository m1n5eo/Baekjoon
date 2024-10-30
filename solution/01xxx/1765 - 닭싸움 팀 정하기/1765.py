import sys
input = sys.stdin.readline

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x, y = find(x), find(y)

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

def same(x, y):
    x, y = find(x), find(y)
    return True if x == y else False

n = int(input())
m = int(input())
parent = [i for i in range(n+1)]
graph = [[] for _ in range(n+1)]

for _ in range(m):
    mode, a, b = map(str, input().split())
    a, b = int(a), int(b)

    if mode == 'F':
        union(a, b)
    elif mode == 'E':
        graph[a].append(b)
        graph[b].append(a)

for k in range(1, n+1):
    for i in range(len(graph[k])):
        for j in range(i+1, len(graph[k])):
            union(graph[k][i], graph[k][j])

result = 0

for i in range(1, n+1):
    if same(0, parent[i]) == False:
        union(0, parent[i])
        result += 1

print(result)