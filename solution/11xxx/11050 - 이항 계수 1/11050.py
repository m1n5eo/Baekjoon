import sys
input = sys.stdin.readline

def factorial(n):
    rtn = 1
    for i in range(1, n+1):
        rtn *= i
    return rtn

n, k = map(int, input().split())
print(factorial(n) // (factorial(k) * factorial(n-k)))