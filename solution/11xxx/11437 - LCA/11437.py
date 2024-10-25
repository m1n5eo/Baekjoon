import sys
from collections import deque
input = sys.stdin.readline

def find(x, y):
    while depth[x] != depth[y]:
        if depth[x] > depth[y]:
            x = parent[x]
        else:
            y = parent[y]
    
    while x != y:
        x, y = parent[x], parent[y]
    
    return x

n = int(input())
graph = [[] for _ in range(n+1)]

for _ in range(n-1):
    a, b = map(int, input().split())

    graph[a].append(b)
    graph[b].append(a)

parent = [0 for _ in range(n+1)]
depth = [0 for _ in range(n+1)]
check = [True for _ in range(2)] + [False for _ in range(n-1)]
queue = deque([1])

while queue:
    x = queue.popleft()

    for nx in graph[x]:
        if check[nx] == False:
            parent[nx] = x
            depth[nx] = depth[x]+1
            check[nx] = True
            queue.append(nx)

m = int(input())

for _ in range(m):
    a, b = map(int, input().split())
    print(find(a, b))