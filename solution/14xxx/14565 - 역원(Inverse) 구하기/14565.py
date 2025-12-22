import sys
input = sys.stdin.readline

def gcd(a, b):
    if b == 0: return a
    else: return gcd(b, a%b)

def exgcd(a, b):
    if b == 0: return 1, 0, a
    else:
        x1, y1, g = exgcd(b, a%b)
        x = y1
        y = x1-(a//b)*y1
        return x, y, g

def solve():
    n, a = map(int, input().split())
    if gcd(n, a) != 1: print(n-a, -1)
    else:
        x, y, g = exgcd(a, n)
        while x < 0: x += n
        print(n-a, x)

if __name__ == '__main__':
    solve()