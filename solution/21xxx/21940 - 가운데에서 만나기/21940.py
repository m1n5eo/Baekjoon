import sys
input = sys.stdin.readline

INF = 1e9

n, m = map(int, input().split())
graph = [[INF for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a, b, t = map(int, input().split())
    graph[a][b] = t

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j or j == k or k == i:
                continue

            if graph[i][k] != INF and graph[k][j] != INF:
                if graph[i][k] + graph[k][j] < graph[i][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]

k = int(input())
friend = list(map(int, input().split()))

result = []

for x in range(1, n+1):
    time = 0

    for f in friend:
        sum = 0 
        
        if x != f:
            if graph[x][f] != INF:
                sum += graph[x][f]
            if graph[f][x] != INF:
                sum += graph[f][x]
        
        time = max(time, sum)

    if not result or (result and time < result[0]):
        result = [time, x]
    elif result and time == result[0]:
        result.append(x)

result = sorted(result[1:])

for res in result:
    print(res, end=" ")