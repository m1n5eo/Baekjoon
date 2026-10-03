import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    a, b, c = map(float, input().split())
    print("$", "{:.2f}".format(a*b*c), sep="")