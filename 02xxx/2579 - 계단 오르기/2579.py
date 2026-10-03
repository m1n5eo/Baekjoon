n = int(input())
stairs = []
dp = []

for _ in range(n):
    temp = int(input())
    stairs.append(temp)

if(n >= 1):
    dp.append(stairs[0])
if(n >= 2):
    dp.append(dp[0]+stairs[1])
if(n >= 3):
    dp.append(max(dp[0]+stairs[2], stairs[1]+stairs[2]))

for i in range(3, n):
    dp.append(max(dp[i-2], dp[i-3]+stairs[i-1])+stairs[i])

print(dp[n-1])