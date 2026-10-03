import sys
input = sys.stdin.readline

INF = 1e9

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

relation = [[0 for _ in range(n+1)] for _ in range(n+1)]
parent = [i for i in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    union(a, b)

    relation[a][b] = 1
    relation[b][a] = 1

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j or j == k or k == i:
                continue

            if relation[i][k] != 0 and relation[k][j] != 0:
                relation[i][j] = relation[i][k] + relation[k][j] if relation[i][j] == 0 else min(relation[i][j], relation[i][k] + relation[k][j])

graph = [list() for _ in range(n+1)]
result = list()
count = 0

for i in range(1, n+1):
    graph[find(i)].append(i)

for g in graph:
    if len(g) == 0:
        continue

    represent = [INF, INF]

    for leader in g:
        dist = 0

        for i in g:
            dist = max(dist, relation[leader][i])
        
        if represent[1] > dist:
            represent = [leader, dist]
    
    result.append(represent[0])

for i in range(1, n+1):
    if same(0, i) == False:
        union(0, i)
        count += 1

result.sort()

print(count)
for r in result:
    print(r)