import sys
input = sys.stdin.readline

n, d = map(int, input().split())
cnt = [0]*11

for i in range(1, n+1):
    num = i

    while num:
        cnt[num%10] += 1
        num //= 10

print(cnt[d])