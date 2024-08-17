import sys
input = sys.stdin.readline

n = int(input())
result = 0

for _ in range(n):
    score = list(map(int, input().split()))
    total = max(score[0], score[1])

    score[0] = 0
    score[1] = 0

    score.sort()

    total += score[6]+score[5]

    result = max(result, total)

print(result)