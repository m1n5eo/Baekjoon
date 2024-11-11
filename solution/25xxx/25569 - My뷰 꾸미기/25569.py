import sys
input = sys.stdin.readline

MOD = 1000000007
MAX = 666666

def expo(num, p):
    if p <= 1:
        return num if p == 1 else 1
    else:
        e = expo(num, p//2)
        return e*e % MOD if p%2 == 0 else e*e*num % MOD

factorial = [1 for _ in range(MAX)]

for i in range(1, MAX):
    factorial[i] = factorial[i-1]*i % MOD

n = int(input())
result = 1

for _ in range(n):
    ai, bi = map(int, input().split())

    a = factorial[ai+bi]
    b = expo(factorial[ai]*factorial[bi] % MOD, MOD-2) % MOD

    result = result * (a*b-1) % MOD

print(result % MOD)