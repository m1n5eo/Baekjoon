import sys
input = sys.stdin.readline

n, m = map(int, input().split())
book = sorted(list(map(int, input().split())))

cnt = 0

for b in book:
    if b < 0:
        cnt += 1
    else:
        break

result = 0

for i in range(0, cnt, m):
    result += (-book[i])*2

for i in range(n-1, cnt-1, -m):
    result += book[i]*2

print(result - (abs(book[0]) if abs(book[0]) > abs(book[-1]) else abs(book[-1])))