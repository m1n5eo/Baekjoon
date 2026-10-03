import sys
input = sys.stdin.readline

INF = 1000000000

n, m = map(int, input().split())
graph = [[INF for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())

    if c == 0:
        graph[a][b] = 0
        graph[b][a] = 1
    elif c == 1:
        graph[a][b] = 0
        graph[b][a] = 0

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j or j == k or k == i:
                continue

            if graph[i][k] != INF and graph[k][j] != INF:
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

m = int(input())

for _ in range(m):
    a, b = map(int, input().split())
    print(graph[a][b] if a != b else 0)