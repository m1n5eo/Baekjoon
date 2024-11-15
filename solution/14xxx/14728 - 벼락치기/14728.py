import sys
input = sys.stdin.readline

n, t = map(int, input().split())
study = [[0, 0]] + [list(map(int, input().split())) for _ in range(n)]
dp = [[0 for _ in range(t+1)] for _ in range(n+1)]

for i in range(1, n+1):
    for time in range(1, t+1):
        dp[i][time] = max(dp[i-1][time], dp[i-1][time-study[i][0]] + study[i][1]) if study[i][0] <= time else dp[i-1][time]

print(dp[n][t])