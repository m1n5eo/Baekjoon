h, w = map(int, input().split())

pan = [0 for _ in range(h)]
for i in range(h):
    pan[i] = [0 for _ in range(w)]

n = int(input())

for _ in range(n):
    l, d, x, y = map(int, input().split())
    x = x-1
    y = y-1
    for i in range(l):
        if d == 0:
            pan[x][y+i] = 1
        elif d == 1:
            pan[x+i][y] = 1

for i in range(h):
    for j in range(w):
        print(pan[i][j], end=' ')
    print()