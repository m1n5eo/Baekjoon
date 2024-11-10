import sys
input = sys.stdin.readline

MOD = 1000000007

def factorial(n):
    rtn = 1

    for i in range(2, n+1):
        rtn = rtn*i % MOD
    
    return rtn

def expo(num, p):
    if p <= 1:
        return num if p == 1 else 1
    else:
        e = expo(num, p//2)

        return e*e % MOD if p%2 == 0 else e*e*num % MOD

n, k = map(int, input().split())

a = factorial(n) % MOD
b = expo(factorial(k)*factorial(n-k) % MOD, MOD-2)

print(a*b % MOD)