import sys
input = sys.stdin.readline

array = [list(map(int, input().split())) for _ in range(9)]

value = -1
x, y = 0, 0

for i in range(9):
    for j in range(9):
        if array[i][j] > value:
            value = array[i][j]
            x, y = i+1, j+1

print(value)
print(x, y)