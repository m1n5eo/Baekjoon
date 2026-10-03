import sys
input = sys.stdin.readline

n = int(input())
result = 0

for _ in range(n):
    temp = int(input())
    result += temp

print(result)