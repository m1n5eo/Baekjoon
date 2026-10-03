import sys
input = sys.stdin.readline

result = 0

word = input()[:-1]
for i in range(int(input())):
    ring = input()[:-1]
    ring = ring + ring
    if word in ring:
        result += 1

print(result)