import sys

input = sys.stdin.readline

h, i, a, r, c = map(int, input().split())
result = int(h*i-a*r*c)

print(result)