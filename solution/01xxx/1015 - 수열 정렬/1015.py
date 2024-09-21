import sys
input = sys.stdin.readline

n = int(input())
array = list(map(int, input().split()))
result = [0 for _ in range(n)]

for i in range(n):
    for j in range(n):
        if array[i] > array[j] or (array[i] == array[j] and i > j):
            result[i] += 1

for i in range(n):
    print(result[i], end=" ")