import sys
input = sys.stdin.readline

INF = 1234567890

tc = int(input())
result = list()

for _ in range(tc):
    n = int(input())
    file = list(map(int, input().split()))
    dp = [[0 for _ in range(n)] for _ in range(n)]

    for j in range(1, n):
        for i in range(j-1, -1, -1):
            small = INF
            for k in range(i, j):
                small = min(dp[i][k] + dp[k+1][j], small)
            dp[i][j] = small + sum(file[i:j+1])
    
    result.append(dp[0][n-1])

for r in result:
    print(r)