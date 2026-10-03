import sys
input = sys.stdin.readline

INF = 1234567890

n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
dp = [[0 for _ in range(n)] for _ in range(n)]
result = list()

for j in range(1, n):
    for i in range(j-1, -1, -1):
        small = INF
        for k in range(i, j):
            small = min(small, dp[i][k] + dp[k+1][j] + matrix[i][0]*matrix[k][1]*matrix[j][1])
        dp[i][j] = small

result.append(dp[0][n-1])

for r in result:
    print(r)