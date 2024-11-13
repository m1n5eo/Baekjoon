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

n, m, q = map(int, input().split())
clean = [0] + list(map(int, input().split()))
dirty = [0] + [1-clean[i] for i in range(1, n+1)]
parent = [i for i in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())

    if not same(a, b):
        clean[min(find(a), find(b))] = clean[find(a)] + clean[find(b)]
        dirty[min(find(a), find(b))] = dirty[find(a)] + dirty[find(b)]
        union(a, b)

for _ in range(q):
    a = int(input())
    print(1 if clean[find(a)] > dirty[find(a)] else 0)