import sys
input = sys.stdin.readline

result = 1

for i in range(2, int(input()) + 1):
    result *= i

print(result)