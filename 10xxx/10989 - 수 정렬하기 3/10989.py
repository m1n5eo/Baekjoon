import sys
input = sys.stdin.readline

n = int(input())
count = [0 for _ in range(11111)]

for _ in range(n):
    count[int(input())] += 1

for i in range(1, 11111):
    for c in range(count[i]):
        print(i)