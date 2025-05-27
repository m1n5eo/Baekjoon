import sys
input = sys.stdin.readline

n = int(input())
score = list(map(int, input().split()))

standard = max(score)
result = 0

for i in range(n):
    result += score[i] / standard * 100

print(result / len(score))