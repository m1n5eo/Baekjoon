k = 19
pan = [0 for _ in range(k)]

for i in range(k):
    pan[i] = list(map(int, input().split()))

n = int(input())

for _ in range(n):
    a, b = map(int, input().split())
    for i in range(k):
        pan[a-1][i] = 1-pan[a-1][i]
        pan[i][b-1] = 1-pan[i][b-1]

for i in range(k):
    for j in range(k):
        print(pan[i][j], end=" ")
    print()