import sys
input = sys.stdin.readline

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return (a * b) / gcd(a, b)

a, b = map(int, input().split())
c, d = map(int, input().split())

mo = int(lcm(b, d))
ja = int(mo/d*c + mo/b*a)

print(int(ja/gcd(mo, ja)), int(mo/gcd(mo, ja)))