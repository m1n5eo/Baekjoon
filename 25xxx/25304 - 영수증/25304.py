import sys
input = sys.stdin.readline

receipt = int(input())
n = int(input())

total = 0

for _ in range(n):
    a, b = map(int, input().split())
    total += a * b

print("Yes" if total == receipt else "No")