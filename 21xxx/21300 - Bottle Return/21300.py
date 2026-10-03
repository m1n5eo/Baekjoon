import sys
input = sys.stdin.readline

l = list(map(int, input().split()))
result = 0

for i in range(6):
    result += l[i]*5

print(result)