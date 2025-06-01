import sys
input = sys.stdin.readline

a1, a0 = map(int, input().split())
c = int(input())
n0 = int(input())

print(1 if (c-a1) * n0 >= a0 else 0)