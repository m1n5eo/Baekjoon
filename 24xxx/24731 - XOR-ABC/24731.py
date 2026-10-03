import sys
input = sys.stdin.readline

MOD = 1000003

def expo(num, p):
    if p <= 1:
        return num if p == 1 else 1
    else:
        e = expo(num, p//2)
        return e*e % MOD if p%2 == 0 else e*e*num % MOD 

k = int(input())
e = expo(2, k) % MOD

a = (e-2)*(e-1) % MOD
b = expo(6, MOD-2) % MOD

print(a*b % MOD)