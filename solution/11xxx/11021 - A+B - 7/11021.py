import sys
input = sys.stdin.readline

for i in range(1, int(input()) + 1):
    a, b = map(int, input().split())
    print("Case #", i, ": ", a+b, sep="")