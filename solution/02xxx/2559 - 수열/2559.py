import sys
input = sys.stdin.readline

n, k = map(int, input().split())
temperature = list(map(int, input().split()))
result = 0

for i in range(k):
    result += temperature[i]

temp = result

for i in range(k, n):
    temp += temperature[i]-temperature[i-k]
    result = max(result, temp)

print(result)