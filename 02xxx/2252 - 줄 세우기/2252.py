import sys
input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
cnt = [0 for _ in range(n+1)]
result = []
queue = []

for _ in range(m):
    a, b = map(int, input().split())

    graph[a].append(b)
    cnt[b] += 1

for i in range(1, n+1):
    if cnt[i] == 0:
        queue.append(i)

for _ in range(n):
    x = queue.pop(0)
    result.append(x)

    for next in graph[x]:
        if cnt[next] == 0:
            continue
        elif cnt[next]-1 == 0:
            cnt[next] -= 1
            queue.append(next)
        else:
            cnt[next] -= 1

for p in result:
    print(p, end=" ")