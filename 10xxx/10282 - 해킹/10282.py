import sys
input = sys.stdin.readline

INF = 1000000000

tc = int(input())

for _ in range(tc):
    n, d, c = map(int, input().split())
    graph = [list() for _ in range(n+1)]

    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append([a, s])

    time = [INF for _ in range(n+1)]
    visit = [False for _ in range(n+1)]

    for g in graph[c]:
        time[g[0]] = g[1]
    
    visit[c] = True

    for _ in range(n-2):
        small = INF
        next = 0
        
        for i in range(1, n+1):
            if visit[i] == False and time[i] <= small:
                small = time[i]
                next = i
        
        visit[next] = True

        for g in graph[next]:
            if visit[g[0]] == False and time[next] + g[1] < time[g[0]]:
                time[g[0]] = time[next] + g[1]
    
    result = 0
    count = 1

    for i in range(1, n+1):
        if time[i] != INF:
            result = max(result, time[i])
            count += 1
    
    print(count, result)