import sys
input = sys.stdin.readline

n, m, q = map(int, input().split())
row = [0 for _ in range(n+1)]
col = [0 for _ in range(m+1)]

for _ in range(q):
    mode, a, b = map(int, input().split())

    if mode == 1:
        row[a] += b
    else:
        col[a] += b

for i in range(1, n+1):
    for j in range(1, m+1):
        print(row[i] + col[j], end=" ")
    print()