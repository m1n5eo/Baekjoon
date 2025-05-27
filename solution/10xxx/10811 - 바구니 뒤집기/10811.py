import sys
input = sys.stdin.readline

n, m = map(int, input().split())
bucket = [i for i in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())

    for i in range((b-a+1)//2):
        bucket[a+i], bucket[b-i] = bucket[b-i], bucket[a+i]

for i in range(1, n+1):
    print(bucket[i], end=" ")