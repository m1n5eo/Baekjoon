import sys
input = sys.stdin.readline

n, m = map(int, input().split())
bucket = [i for i in range(0, n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    bucket[a], bucket[b] = bucket[b], bucket[a]

for i in range(1, n+1):
    print(bucket[i], end=" ")