import sys
input = sys.stdin.readline

def expo(num, p, k):
    if p <= 1:
        return num if p == 1 else 1
    else:
        e = expo(num, p//2, k)
        return e*e*num % k if p%2 == 1 else e*e % k

a, b, c = map(int, input().split())
print(expo(a, b, c) % c)