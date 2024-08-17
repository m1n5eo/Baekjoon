import sys
input = sys.stdin.readline

a, b = map(int, input().split())
n = int(input())

result = abs(a-b)

for i in range(n):
    button = int(input())

    result = min(result, abs(b-button)+1)

print(result)