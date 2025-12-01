import sys
input = sys.stdin.readline

MAX = 222222

n, h = map(int, input().split())

down = [0 for _ in range(h+1)]
up = [0 for _ in range(h+1)]

for i in range(n):
    if i%2 == 0:
        down[int(input())] += 1
    else:
        up[int(input())] += 1

for i in range(h-1, 0, -1):
    down[i] += down[i+1]
    up[i] += up[i+1]

result = MAX
count = 0

for i in range(1, h+1):
    if result > down[i] + up[h-i+1]:
        result = down[i] + up[h-i+1]
        count = 1
    elif result == down[i] + up[h-i+1]:
        count += 1

print(result, count)