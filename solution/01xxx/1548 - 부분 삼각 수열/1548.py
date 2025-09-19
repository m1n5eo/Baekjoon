import sys
input = sys.stdin.readline

n = int(input())
array = sorted(list(map(int, input().split())))
ret = 1 if n == 1 else 2
for i in range(n):
    left = i
    right = n-1
    while left+1 < right:
        if array[left] + array[left+1] > array[right]: ret = max(ret, right-left+1)
        right -= 1
print(ret)