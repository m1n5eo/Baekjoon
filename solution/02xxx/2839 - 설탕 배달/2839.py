import sys
input = sys.stdin.readline

n = int(input())
result = -1
count = 0

while count*3 <= n:
    if (n - count*3) % 5 == 0:
        result = count + (n - count*3) // 5
        break
    else:
        count += 1

print(result)