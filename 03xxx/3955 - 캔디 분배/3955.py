import sys
input = sys.stdin.readline

INF = 10**9

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
    n, m = map(int, input().split())
    x, y, g = exgcd(n%m, m)
    k = (-((n+1)%m) + m)*x % m
    # print("n, m : ", n, m)
    # print("a, b : ", n%m, m)
    # print("x, y : ", x, y)
    # print("g : ", g)
    # print("k : ", k)
    # print()
    if m == 1: return n+1
    elif n == 1: return 1
    elif n%m == 0 or gcd(m, g) != 1: return INF+1
    else: return (n*(k+1)+1)//m

if __name__ == '__main__':
    tc = int(input())
    sol = list()
    while tc:
        tc -= 1
        ret = solve()
        sol.append(ret if ret <= INF else "IMPOSSIBLE")
    for s in sol: print(s)