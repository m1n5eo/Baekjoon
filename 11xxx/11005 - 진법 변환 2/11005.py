import sys
input = sys.stdin.readline

number, n = map(int, input().split())
result = ""

while number:
    result = (str(number % n) if number % n < 10 else chr(number % n + ord('A') - 10)) + result
    number //= n

print(result)