import sys
input = sys.stdin.readline

n = int(input())
number = list(map(int, input().split()))

dp = [[0 for _ in range(n+1)] for _ in range(21)]
dp[number[0]][0] = 1

for i in range(n-1):
    for j in range(21):
        if dp[j][i] != 0:
            if 0 <= j-number[i+1] and j-number[i+1] <= 20:
                dp[j-number[i+1]][i+1] += dp[j][i]
            if 0 <= j+number[i+1] and j+number[i+1] <= 20:
                dp[j+number[i+1]][i+1] += dp[j][i]

print(dp[number[-1]][n-2])