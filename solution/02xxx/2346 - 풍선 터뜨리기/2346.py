import sys
input = sys.stdin.readline

n = int(input())
b = list(map(int, input().split()))
balloon = list()

for i in range(len(b)):
    balloon.append([b[i], i+1])

while True:
    print(balloon[0][1], end=" ")
    k = (balloon.pop(0))[0]

    if not balloon:
        break

    if k > 0:
        for _ in range(k - 1):
            balloon.append(balloon.pop(0))
    elif k < 0:
        for _ in range(-k):
            balloon.insert(0, balloon.pop())