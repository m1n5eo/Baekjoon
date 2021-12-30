n = int(input())
pan = []
for i in range(20):
    pan.append([])
    for j in range(20):
        pan[i].append(0)

for i in range(n):
    a, b = map(int, input().split())
    pan[a][b] = 1

for i in range(1, 20):
    for j in range(1, 20):
        print(pan[i][j], end=" ")
    print("")