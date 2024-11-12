import sys
import math
input = sys.stdin.readline

def isPrime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n%i == 0:
            return False
    return True if n != 1 else False

def expo(num, p, mod):
    if p <= 1:
        return num if p == 1 else 1
    else:
        e = expo(num, p//2, mod)
        return e*e % mod if p%2 == 0 else e*e*num % mod

while True:
    p, a = map(int, input().split())

    if p == 0 and a == 0:
        break

    print("yes" if not isPrime(p) and expo(a, p, p) % p == a else "no")