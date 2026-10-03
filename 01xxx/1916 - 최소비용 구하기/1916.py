import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

bus = [[1e9 for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    s, e, c = map(int, input().split())
    bus[s][e] = min(bus[s][e], c)

s, e = map(int, input().split())

cost = [1e9 for _ in range(n+1)]
visit = [False for _ in range(n+1)]

for i in range(1, n+1):
    bus[i][i] = 0
    cost[i] = bus[s][i]

visit[s] = True

for _ in range(n-2):
    small = 1e9
    next = 0

    for i in range(1, n+1):
        if visit[i] == False and cost[i] <= small:
            small = cost[i]
            next = i
    
    visit[next] = True

    for i in range(1, n+1):
        if visit[i] == False and cost[next] + bus[next][i] < cost[i]:
            cost[i] = cost[next] + bus[next][i]

print(cost[e])