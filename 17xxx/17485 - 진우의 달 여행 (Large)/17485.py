import sys
input = sys.stdin.readline

INF = 1e9

n, m = map(int, input().split())
fuel = [list(map(int, input().split())) for _ in range(n)]
dp = [[[INF for _ in range(3)] for _ in range(m)] for _ in range(n)]

for j in range(m):
    for k in range(3):
        dp[0][j][k] = fuel[0][j]

for i in range(1, n):
    for j in range(m):
        if j != 0:
            dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + fuel[i][j]
        
        dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + fuel[i][j]

        if j != m-1:
            dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + fuel[i][j]

result = INF

for j in range(m):
    for k in range(3):
        result = min(result, dp[n-1][j][k])

print(result)