import sys
input = sys.stdin.readline

MOD = 1000000007
MAX = 222222

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
count = [0 for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    Union(a, b)

for i in range(1, n+1):
    count[Find(i)] += 1

result = 1

for i in range(1, n+1):
    if count[i] != 0:
        result = result*count[i] % MOD

print(result)