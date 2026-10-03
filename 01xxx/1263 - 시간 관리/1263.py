import sys
input = sys.stdin.readline

n = int(input())

work = []
now = 0

for _ in range(n):
    t, s = map(int, input().split())

    work.append([t, s])
    now = max(now, s)

work = sorted(work, key=lambda x: x[1], reverse=True)

for i in range(n):
    now -= work[i][0]

    if i+1 < n and now >= work[i+1][1]:
        now = work[i+1][1]

if now >= 0:
    print(now)
else:
    print(-1)