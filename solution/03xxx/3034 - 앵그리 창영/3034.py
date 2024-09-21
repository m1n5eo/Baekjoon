import sys
input = sys.stdin.readline

n, w, h = map(int, input().split())
total = w**2 + h**2

for _ in range(n):
    temp = int(input())

    if temp*temp <= total:
        print("DA")
    else:
        print("NE")