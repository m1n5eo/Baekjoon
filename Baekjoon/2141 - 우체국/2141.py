import sys
input = sys.stdin.readline

n = int(input())

hometown = []
sum = 0

for _ in range(n):
    coordinate, people = map(int, input().split())

    hometown.append([coordinate, people])
    sum += people

hometown.sort()

temp = 0

for i in range(n):
    temp += hometown[i][1]

    if temp >= (sum+1)//2:
        print(hometown[i][0])
        break