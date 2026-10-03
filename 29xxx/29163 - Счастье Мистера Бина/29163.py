import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
cnt = 0

for i in range(n):
    if l[i]%2 == 0:
        cnt += 1

if cnt > n//2:
    print("Happy")
else:
    print("Sad")