import sys
input = sys.stdin.readline

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x, y = find(x), find(y)

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

def same(x, y):
    x, y = find(x), find(y)
    return True if x == y else False

n, m = map(int, input().split())
parent = [i for i in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    union(a, b)

count = 0

for i in range(2, n+1):
    if not same(1, i):
        union(1, i)
        count += 1

print(count)