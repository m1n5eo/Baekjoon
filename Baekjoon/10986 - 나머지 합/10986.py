import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
cnt = [1] + [0]*(m-1)
before = 0
result = 0

for i in range(1, n+1):
    cnt[(before+a[i]) % m] += 1
    before = (before+a[i]) % m

for i in range(m):
    result += cnt[i]*(cnt[i]-1)//2

print(result)