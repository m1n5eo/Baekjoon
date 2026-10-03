import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    length = list(map(int, input().split()))
    length.sort()

    print((length[0]+length[1])**2 + length[2]**2)