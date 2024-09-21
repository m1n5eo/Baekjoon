import sys

input = sys.stdin.readline

n, m = map(int, input().split())
n *= 100

if n >= m:
    print("Yes")
else:
    print("No")