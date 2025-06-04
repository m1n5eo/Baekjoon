import sys
input = sys.stdin.readline

n, m = map(int, input().split())
word = {input()[:-1] for _ in range(n)}
count = 0

for _ in range(m):
    search = input()[:-1]
    if search in word:
        count += 1

print(count)