import sys
input = sys.stdin.readline

n = list(map(int, input().split()))
cal = [1, 1, 2, 2, 2, 8]

for i in range(6):
    print(cal[i]-n[i], end=" ")