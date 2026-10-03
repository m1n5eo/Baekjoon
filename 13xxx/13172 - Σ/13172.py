import sys
input = sys.stdin.readline

MOD = 1000000007

def expo(num, p):
    if p <= 1:
        return num if p == 1 else 1
    else:
        e = expo(num, p//2)
        return e*e % MOD if p%2 == 0 else e*e*num % MOD

m = int(input())
result = 0

for _ in range(m):
    n, s = map(int, input().split())

    a = s % MOD
    b = expo(n, MOD-2) % MOD

    result = (result + a*b) % MOD

print(result)