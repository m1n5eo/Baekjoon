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
people = [0] + [int(input()) for _ in range(n)]

for _ in range(m):
    sw, a, b = map(int, input().split())

    if sw == 1:
        people[min(find(a), find(b))] = people[find(a)] + people[find(b)]
        union(a, b)
    elif sw == 2:
        if people[find(a)] == people[find(b)]:
            union(a, b)
            union(0, a)
        else:
            people[min(find(a), find(b))] = abs(people[find(a)] - people[find(b)])
            union(a, b)

result = list()

for i in range(1, n+1):
    if not same(0, i):
        result.append(people[find(i)])
        union(0, i)

print(len(result))

for r in sorted(result):
    print(r, end=" ")