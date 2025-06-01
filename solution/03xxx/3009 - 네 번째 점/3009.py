import sys
input = sys.stdin.readline

point = [list(map(int, input().split())) for _ in range(3)]
x, y = 0, 0

if point[0][0] == point[1][0]:
    x = point[2][0]
elif point[0][0] == point[2][0]:
    x = point[1][0]
elif point[1][0] == point[2][0]:
    x = point[0][0]

if point[0][1] == point[1][1]:
    y = point[2][1]
elif point[0][1] == point[2][1]:
    y = point[1][1]
elif point[1][1] == point[2][1]:
    y = point[0][1]

print(x, y)