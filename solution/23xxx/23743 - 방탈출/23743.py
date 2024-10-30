import sys
input = sys.stdin.readline # 탈출구를 0으로 생각

def Find(x):
    if x != parent[x]:
        parent[x] = Find(parent[x])
    return parent[x]

def Union(x, y):
    x = Find(x)
    y = Find(y)

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

def Same(x, y):
    x = Find(x)
    y = Find(y)

    if x == y:
        return True
    else:
        return False

n, m = map(int, input().split())
parent = [i for i in range(0, n+1)]
mst = list()

for _ in range(m):
    a, b, c = map(int, input().split())
    mst.append([a, b, c])

time = list(map(int, input().split()))

for i in range(1, n+1):
    mst.append([0, i, time[i-1]])

mst.sort(key=lambda mst: mst[2])

result = 0

for i in range(m+n):
    if Same(mst[i][0], mst[i][1]) == False:
        Union(mst[i][0], mst[i][1])
        result += mst[i][2]

print(result)