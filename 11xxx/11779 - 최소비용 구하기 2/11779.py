import sys
input = sys.stdin.readline

INF = 1e9

n = int(input())
m = int(input())

bus = [[INF for _ in range(n+1)] for _ in range(n+1)]
cost = [INF for _ in range(n+1)]
visit = [False for _ in range(n+1)]
route = [list() for _ in range(n+1)]

for _ in range(m):
    s, e, c = map(int, input().split())
    bus[s][e] = min(bus[s][e], c)

a, b = map(int, input().split())

for i in range(1, n+1):
    bus[i][i] = 0
    cost[i] = bus[a][i]

    route[i].append(a)
    if i != a:
        route[i].append(i)

visit[a] = True

for _ in range(n-2):
    small = INF
    next = 0

    for i in range(1, n+1):
        if visit[i] == False and cost[i] <= small:
            small = cost[i]
            next = i
    
    visit[next] = True

    for i in range(1, n+1):
        if visit[i] == False:
            if cost[next] + bus[next][i] < cost[i]:
                cost[i] = cost[next] + bus[next][i]

                route[i].clear()
                for routes in route[next]:
                    route[i].append(routes)
                route[i].append(i)

print(cost[b])
print(len(route[b]))
for routes in route[b]:
    print(routes, end=" ")