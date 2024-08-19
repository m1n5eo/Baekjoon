import sys
input = sys.stdin.readline

ur, tr, uo, to = map(int, input().split())
result = 56*ur + 24*tr + 14*uo + 6*to

print(result)