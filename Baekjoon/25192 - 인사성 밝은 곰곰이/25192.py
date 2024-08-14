import sys

input = sys.stdin.readline

n = int(input())

check = set()
result = 0

for i in range(n):
    str = input()

    if str == "ENTER\n":
        check.clear()
    elif str not in check:
        result += 1
        check.add(str)

print(result)