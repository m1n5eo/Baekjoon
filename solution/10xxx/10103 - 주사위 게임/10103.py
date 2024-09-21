score = list(100 for _ in range(2))

n = int(input())

for _ in range(n):
    a, b = map(int, input().split())

    if a > b:
        score[1] = score[1]-a
    elif a < b:
        score[0] = score[0]-b

print(score[0])
print(score[1])