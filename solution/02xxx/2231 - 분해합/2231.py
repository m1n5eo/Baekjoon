import sys
input = sys.stdin.readline

def f(number):
    rtn = 0
    
    while number:
        rtn += number%10
        number //= 10

    return rtn

n = int(input())
result = 0

for i in range(1, n+1):
    if n == i + f(i):
        result = i
        break

print(result)