import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    score = list(map(int, input().split()))
    score.sort()

    if score[3]-score[1] >= 4:
        print("KIN")
    else:
        print(score[1]+score[2]+score[3])