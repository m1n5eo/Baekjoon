import sys
input = sys.stdin.readline

n = int(input())
point = sorted([list(map(int, input().split())) for _ in range(n)])

for p in point:
    print(p[0], p[1])