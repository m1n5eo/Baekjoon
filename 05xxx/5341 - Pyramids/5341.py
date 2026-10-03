import sys

input = sys.stdin.readline

while True:
    n = int(input())
    result = 0

    if n == 0:
        break

    for i in range(1, n+1):
        result += i
    
    print(result)