import sys
input = sys.stdin.readline

n = int(input())
integer = list(map(int, input().split()))
find = int(input())

count = 0

for i in integer:
    if i == find:
        count += 1

print(count)