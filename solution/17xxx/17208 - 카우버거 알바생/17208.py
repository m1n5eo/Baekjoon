import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
dp = [[[0 for _ in range(k+1)] for _ in range(m+1)] for _ in range(n+1)]
menu = [[0, 0]] + [list(map(int, input().split())) for _ in range(n)]

for i in range(1, n+1):
    for b in range(1, m+1):
        for f in range(1, k+1):
            dp[i][b][f] = max(dp[i-1][b][f], dp[i-1][b-menu[i][0]][f-menu[i][1]] + 1) if menu[i][0] <= b and menu[i][1] <= f else dp[i-1][b][f]
            
print(dp[n][m][k])