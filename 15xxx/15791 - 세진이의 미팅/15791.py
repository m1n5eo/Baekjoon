import sys
input = sys.stdin.readline

MOD = 1000000007

def factorial(num):
    rtn = 1

    for i in range(2, num+1):
        rtn = rtn*i % MOD
    
    return rtn

def expo(num, p):
    if p <= 1:
        return num if p == 1 else 1
    else:
        e = expo(num, p//2)
        return e*e % MOD if p%2 == 0 else e*e*num % MOD

n, m = map(int, input().split())

a = factorial(n) % MOD
b = expo(factorial(m)*factorial(n-m) % MOD, MOD-2) % MOD

print(a*b % MOD)