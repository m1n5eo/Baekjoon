pan = [0 for _ in range(10)]
for i in range(10):
    pan[i] = [0 for _ in range(10)]

x, y = 1, 1

while(not(pan[x+1][y] == 1 and pan[x][y+1] == 1) and not(pan[x][y] == 2)):
    pan[x][y] = 9
    if y+1 <= 9 and pan[x][y+1] != 1:
        y = y+1
        continue
    elif x+1 <= 9 and pan[x+1][y] != 1:
        x = x+1
        continue

for i in range(10):
    for j in range(10):
        print(pan[i][j], end=' ')
    print()