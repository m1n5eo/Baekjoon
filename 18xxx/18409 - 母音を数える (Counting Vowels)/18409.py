import sys
input = sys.stdin.readline

n = int(input())
str = input()[:-1]
result = 0

for i in range(len(str)):
    if str[i] == 'a' or str[i] == 'e' or str[i] == 'i' or str[i] == 'o' or str[i] == 'u':
        result += 1

print(result)