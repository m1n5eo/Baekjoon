import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

if n < m:
    print(-1)
elif n == m:
    print(0)
elif n > m:
    print(1)