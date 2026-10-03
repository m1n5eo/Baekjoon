import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [[0] * (m+2)] + [[0] + list(map(int, input().split())) + [0] for _ in range(n)] + [[0] * (m+2)]

result = n*m + n*m

for i in range(n+2):
    for j in range(m+1):
        result += abs(arr[i][j]-arr[i][j+1])

for i in range(n+1):
    for j in range(m+2):
        result += abs(arr[i][j]-arr[i+1][j])
    
print(result)