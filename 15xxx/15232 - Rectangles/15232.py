import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

for _ in range(n):
    for _ in range(m):
        print("*", end="")
    print()