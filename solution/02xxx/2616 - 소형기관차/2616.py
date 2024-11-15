import sys
input = sys.stdin.readline

n = int(input())
client = list(map(int, input().split()))
k = int(input())
prefix = [sum(client[:k])]

for i in range(k, n):
    prefix.append(prefix[-1] + client[i] - client[i-k])

dp = [[0 for _ in range(n+2)] for _ in range(4)]

for i in range(1, 4):
    for j in range(i*k, n+1):
        dp[i][j] = max(dp[i][j-1], dp[i-1][j-k] + prefix[j-k])

print(dp[3][n])