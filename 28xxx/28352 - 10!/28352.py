import sys
input = sys.stdin.readline

n = int(input())
second = 1

for i in range(1, n+1):
    second *= i

print(int(second/24/60/60/7))