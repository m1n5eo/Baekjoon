import sys
input = sys.stdin.readline

a, b = map(int, input().split())
c = int(input())

print(((a*60 + b + c) % 1440) // 60, ((a*60 + b + c) % 1440) % 60)