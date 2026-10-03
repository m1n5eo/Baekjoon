import sys
input = sys.stdin.readline

MOD = 1000000007
MAX = 4000001

def expo(num, p):
    if p <= 1:
        return num if p == 1 else 1
    else:
        e = expo(num, p//2)
        return e*e % MOD if p%2 == 0 else e*e*num % MOD

factorial = [1 for _ in range(MAX)]

for i in range(2, MAX):
    factorial[i] = factorial[i-1]*i % MOD

tc = int(input())

for _ in range(tc):
    n, k = map(int, input().split())

    a = factorial[n]
    b = expo(factorial[k]*factorial[n-k] % MOD, MOD-2) % MOD

    print(a*b % MOD)