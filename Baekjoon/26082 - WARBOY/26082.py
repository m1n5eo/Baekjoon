import sys

input = sys.stdin.readline

a, b, c = map(int, input().split())
result = int(b/a*c*3)

print(result)