import sys

t = int(input())
for i in range(t):
    n, m = map(int, sys.stdin.readline().split())
    print(n+m)