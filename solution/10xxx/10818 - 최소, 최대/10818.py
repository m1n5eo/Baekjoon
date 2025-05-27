import sys
input = sys.stdin.readline

n = int(input())
integer = list(map(int, input().split()))

print(min(integer), max(integer))