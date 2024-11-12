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

tc = 0

while True:
    n, m = map(int, input().split())
    parent = [i for i in range(n+1)]
    tc += 1

    if n == 0 and m == 0:
        break

    for _ in range(m):
        a, b = map(int, input().split())
        Union(a, b) if not Same(a, b) else Union(0, a)

    count = 0

    for i in range(1, n+1):
        if not Same(0, i):
            Union(0, i)
            count += 1

    print("Case ", tc, ": ", sep="", end="")

    if count <= 1:
        print("No trees." if count == 0 else "There is one tree.")
    else:
        print("A forest of", count, "trees.")