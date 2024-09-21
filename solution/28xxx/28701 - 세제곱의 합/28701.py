import sys
input = sys.stdin.readline

n = int(input())
answer = [0, 0]

for i in range(1, n+1):
    answer[0] += i
    answer[1] += i*i*i

print(answer[0])
print(answer[0]**2)
print(answer[1])