import sys
input = sys.stdin.readline

n = int(input())
integer = sorted(list(map(int, input().split())))
print(integer[0] * integer[-1])