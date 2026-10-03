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

n = int(input())
m = int(input())

parent = [i for i in range(n+1)]
plane = [0]
result = 0

for _ in range(m):
    plane.append(int(input()))

for i in range(1, m+1):
    f = find(plane[i])

    if f != 0:
        union(f, f-1)
        result += 1
    else:
        break

print(result)