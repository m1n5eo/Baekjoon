import sys

input = sys.stdin.readline

bowl = list()

for _ in range(3):
    temp = int(input())
    bowl.append(temp)
bowl.sort()

print(bowl[1])