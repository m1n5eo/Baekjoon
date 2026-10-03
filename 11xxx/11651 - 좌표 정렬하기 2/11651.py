import sys
input = sys.stdin.readline

n = int(input())
for p in sorted([list(map(int, input().split())) for _ in range(n)], key = lambda x: (x[1], x[0])):
    print(p[0], p[1])