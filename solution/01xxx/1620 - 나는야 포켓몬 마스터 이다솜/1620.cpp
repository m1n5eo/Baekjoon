import sys

input = sys.stdin.readline

n, m = map(int, input().split())
dic1 = {}
dic2 = {}

for i in range(1, n+1):
    s = input().strip()
    dic1[s] = str(i)
    dic2[str(i)] = s

for _ in range(m):
    s = input().strip()
    if s in dic1:
        print(dic1[s])
    elif s in dic2:
        print(dic2[s])