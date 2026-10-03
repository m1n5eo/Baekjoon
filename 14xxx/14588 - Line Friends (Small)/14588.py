import sys
input = sys.stdin.readline

n = int(input())
line = [[0, 0]]
graph = [[0 for _ in range(n+1)] for _ in range(n+1)]

for i in range(1, n+1):
    a, b = map(int, input().split())
    line.append([a, b])

for i in range(1, n+1):
    for j in range(1, n+1):
        if i != j and line[i][0] <= line[j][0] and line[j][0] <= line[i][1]:
            graph[i][j] = 1
            graph[j][i] = 1

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j or j == k or k == i:
                continue
            elif graph[i][k] != 0 and graph[k][j] != 0:
                graph[i][j] = graph[i][k] + graph[k][j] if graph[i][j] == 0 else min(graph[i][j], graph[i][k] + graph[k][j])

m = int(input())

for _ in range(m):
    a, b = map(int, input().split())
    print(graph[a][b] if graph[a][b] != 0 else -1)