import sys
input = sys.stdin.readline

n = int(input())
point = []
result = 0

for i in range(n):
    x, y = map(int, input().split())
    point.append([x, y])

    if i != 0:
        result += abs(point[i][0]-point[i-1][0])+abs(point[i][1]-point[i-1][1])
    
    if i == n-1:
        result += abs(point[i][0]-point[0][0])+abs(point[i][1]-point[0][1])

print(result)