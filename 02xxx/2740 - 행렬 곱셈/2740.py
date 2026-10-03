import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

m, o = map(int, input().split())
b = [list(map(int, input().split())) for _ in range(m)]

result = [[0 for _ in range(o)] for _ in range(n)]

for i in range(n):
    for j in range(o):
        for k in range(m):
            result[i][j] += a[i][k]*b[k][j]

for i in range(n):
    for j in range(o):
        print(result[i][j], end=" ")
    print()