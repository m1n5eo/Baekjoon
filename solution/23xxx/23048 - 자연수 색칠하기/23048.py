import sys
input = sys.stdin.readline

n = int(input())

prime = [0, 1] + [0 for _ in range(n-1)]
cnt = 1

for i in range(2, n+1):
    if prime[i] == 0:
        cnt += 1
        prime[i] = cnt
        for j in range(i*2, n+1, i):
            prime[j] = cnt

print(cnt)
for p in prime[1:]:
    print(p, end=" ")