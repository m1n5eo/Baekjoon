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

tc = int(input())

for _ in range(tc):
    n = int(input())
    
    fn = factorial(n)

    a = factorial(2*n) % MOD
    b = expo(fn*fn*(n+1) % MOD, MOD-2) % MOD

    print(a*b % MOD)