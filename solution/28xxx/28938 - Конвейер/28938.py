import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
now = 0

for i in range(n):
    now += l[i]

if now > 0:
    print("Right")
elif now == 0:
    print("Stay")
elif now < 0:
    print("Left")