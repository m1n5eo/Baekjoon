import sys
input = sys.stdin.readline

MOD = 987654321

n = int(input()) // 2
dp = [1, 1, 2, 5, 14] + [0 for _ in range(n-4)]

for i in range(5, n+1):
    for j in range(0, i):
        dp[i] += (dp[j] * dp[i-j-1]) % MOD
        dp[i] %= MOD

print(dp[n])