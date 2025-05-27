import sys
input = sys.stdin.readline

n, x = map(int, input().split())
integer = list(map(int, input().split()))

for i in integer:
    if i < x:
        print(i, end=" ")