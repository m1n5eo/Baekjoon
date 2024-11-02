import sys
input = sys.stdin.readline

MAX = 555

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(x, y, sw):
    x, y = find(x), find(y)

    if sw == 1:
        parent[y] = x
    elif sw == 2:
        parent[x] = y

def same(x, y):
    x, y = find(x), find(y)
    return True if x == y else False

n, m = map(int, input().split())
kingdom = {}
kingdom2 = ["!" for _ in range(MAX)]

for i in range(1, n+1):
    k, o, name = map(str, input().split())
    kingdom[name] = i
    kingdom2[i] = name

parent = [i for i in range(n+1)]

for _ in range(m):
    first, second, sw = map(str, input()[:-1].split(','))

    t1, t2, a = first.split()
    t1, t2, b = second.split()

    if same(kingdom[a], kingdom[b]) == False:
        union(kingdom[a], kingdom[b], int(sw))
    else:
        if sw == "1" and find(kingdom[a]) != kingdom[a]:
            parent[find(kingdom[a])] = kingdom[a]
            parent[kingdom[a]] = kingdom[a]
        elif sw == "2" and find(kingdom[b]) != kingdom[b]:
            parent[find(kingdom[a])] = kingdom[b]
            parent[kingdom[b]] = kingdom[b]

result = list()
count = 0

for i in range(1, n+1):
    parent[i] = find(i)

    if same(0, parent[i]) == False:
        result.append(kingdom2[parent[i]])
        count += 1
        union(0, parent[i], 1)

result.sort()

print(count)
for r in result:
    print("Kingdom", "of", r)