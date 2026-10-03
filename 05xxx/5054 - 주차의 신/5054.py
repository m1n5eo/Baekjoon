import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    point = sorted(list(map(int, input().split())))

    print((point[n-1]-point[0])*2)