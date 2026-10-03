import sys
input = sys.stdin.readline

n = int(input())
point = list(map(int, input().split()))

point = sorted([[point[i], i, 0] for i in range(n)], key = lambda x: x[0])

for i in range(n):
    if i == 0 or point[i-1][0] != point[i][0]:
        point[i][2] = point[i-1][2] + 1
    elif point[i-1][0] == point[i][0]:
        point[i][2] = point[i-1][2]

for p in sorted(point, key = lambda x: x[1]):
    print(p[2] - 1, end=" ")