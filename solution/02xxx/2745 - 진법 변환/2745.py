import sys
input = sys.stdin.readline

number, n = map(str, input().split())
result = 0

for i in range(len(number)):
    if '0' <= number[i] and number[i] <= '9':
        result = result * int(n) + (ord(number[i]) - ord('0'))
    elif 'A' <= number[i] and number[i] <= 'Z':
        result = result * int(n) + (ord(number[i]) - ord('A') + 10)

print(result)