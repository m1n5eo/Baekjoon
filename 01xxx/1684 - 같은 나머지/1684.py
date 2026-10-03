import sys
input = sys.stdin.readline

def gcd(a, b):
    return gcd(b, a%b) if b != 0 else a

n = int(input())
num = sorted(list(map(int, input().split())))
gap = list()

for i in range(1, n):
    gap.append(num[i] - num[i-1])

result = gap[0]

for i in range(1, n-1):
    result = gcd(result, gap[i])

print(result)