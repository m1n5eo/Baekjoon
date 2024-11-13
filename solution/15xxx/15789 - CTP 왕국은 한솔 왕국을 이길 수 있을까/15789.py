import sys
input = sys.stdin.readline

def Find(x):
    if x != parent[x]:
        parent[x] = Find(parent[x])
    return parent[x]

def Union(x, y):
    x, y = Find(x), Find(y)

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

def Same(x, y):
    x, y = Find(x), Find(y)
    return True if x == y else False

n, m = map(int, input().split())
parent = [i for i in range(n+1)]
count = [1 for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())

    if not Same(a, b):
        count[min(Find(a), Find(b))] = count[Find(a)] + count[Find(b)]
        Union(a, b)

c, h, k = map(int, input().split())

result = 0
remain = list()

for i in range(1, n+1):
    if not Same(0, i) and not Same(c, i) and not Same(h, i):
        remain.append(count[Find(i)])
        Union(0, i)
    
remain.sort(reverse=True)

for _ in range(k):
    if remain:
        result += remain[0]
        remain.pop(0)
    else:
        break
    
print(result + count[Find(c)])