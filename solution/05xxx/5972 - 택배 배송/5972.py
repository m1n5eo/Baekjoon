import sys
from heapq import heappush, heappop
input = sys.stdin.readline

INF = 1000000000

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())

    graph[a].append([b, c])
    graph[b].append([a, c])

dist = [INF] + [0] + [INF for _ in range(n-1)]
heap = []

heappush(heap, [0, 1])

while heap:
    cost, now = heappop(heap)

    if cost < dist[now]:
        continue

    for g in graph[now]:
        if cost + g[1] < dist[g[0]]:
            dist[g[0]] = cost + g[1]
            heappush(heap, [cost + g[1], g[0]])

print(dist[-1])