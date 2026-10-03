import sys
input = sys.stdin.readline

n, m = map(int, input().split())
bucket = [0 for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())

    for i in range(a, b+1):
        bucket[i] = c

for i in range(1, n+1):
    print(bucket[i], end=" ")