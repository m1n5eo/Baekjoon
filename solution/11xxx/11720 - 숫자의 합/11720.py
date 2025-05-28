import sys
input = sys.stdin.readline

length = int(input())
number = input()[:-1]

sum = 0

for i in range(length):
    sum += int(number[i])

print(sum)