import sys
input = sys.stdin.readline

n, k = map(int, input().split())
result = 0

for i in range(1, n+1):
    if n % i == 0:
        k -= 1
    if k == 0:
        result = i
        break

print(result)