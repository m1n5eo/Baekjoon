import sys
import math
input = sys.stdin.readline

dx = [0, 0, 1, 1]
dy = [0, 1, 0, 1]

n, m = map(int, input().split())
c = int(input())

point = [[0 for _ in range(m+3)] for _ in range(n+3)]
area = 0

for _ in range(c):
    x, y = map(int, input().split())
    point[x][y] = 1

for i in range(n):
    for j in range(m):
        count = 0

        for k in range(4):
            x = i+dx[k]
            y = j+dy[k]

            if 0 <= x and x <= n and 0 <= y and y <= m and point[x][y] == 1:
                count += 1

        if count == 1:
            area += math.pi*0.25
        elif count == 2:
            if i+1 <= n and j+1 <= m and point[i][j] == 1 and point[i+1][j+1] == 1:
                area += 1
            elif i+1 <= n and j+1 <= m and point[i+1][j] == 1 and point[i][j+1] == 1:
                area += 1
            else:
                area += math.pi*(1/6)+math.sqrt(3)*0.25
        elif count == 3 or count == 4:
            area += 1

print(round(area, 6))