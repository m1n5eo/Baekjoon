import sys
input = sys.stdin.readline

triangle = sorted(list(map(int, input().split())))
print((triangle[0] + triangle[1]) * 2 - 1 if triangle[0] + triangle[1] <= triangle[2] else triangle[0] + triangle[1] + triangle[2])