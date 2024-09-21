import sys
input = sys.stdin.readline

def find(x, parent):
    if x != parent[x]:
        parent[x] = find(parent[x], parent)
    
    return parent[x]

def union(x, y, parent):
    x = find(x, parent)
    y = find(y, parent)

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

n, m, k = map(int, input().split())
A = [0] + list(map(int, input().split()))

parent = []
cost = []

for i in range(0, n+1):
    parent.append(i)
    cost.append(1e9)

for _ in range(m):
    a, b = map(int, input().split())
    union(a, b, parent)

result = 0

for i in range(1, n+1):
    parent[i] = find(i, parent)

    if cost[parent[i]] == 1e9:
        result += A[i]
        cost[parent[i]] = A[i]
    elif cost[parent[i]] != 1e9 and cost[parent[i]] > A[i]:
        result -= cost[parent[i]] - A[i]
        cost[parent[i]] = A[i]

print(result) if result <= k else print("Oh no")