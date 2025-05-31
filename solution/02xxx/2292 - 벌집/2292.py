import sys
input = sys.stdin.readline

n = int(input()) - 1
count = 1

while n > 0:
    n -= count * 6
    count += 1

print(count)