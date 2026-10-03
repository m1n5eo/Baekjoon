import sys
input = sys.stdin.readline

integer = sorted([int(input()) for _ in range(int(input()))])
count = [0 for _ in range(8888)]
result = list()
k = 0

for i in integer:
    count[i + 4444] += 1
    k = max(k, count[i + 4444])

for i in range(8888):
    if count[i] == k:
        result.append(i - 4444)

print(int(round(sum(integer) / len(integer), 0)))
print(integer[len(integer) // 2])
print(result[1 if len(result) > 1 else 0])
print(max(integer) - min(integer))