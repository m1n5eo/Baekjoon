import sys
input = sys.stdin.readline

integer = [int(input()) for _ in range(9)]

print(max(integer))
print(integer.index(max(integer)) + 1)