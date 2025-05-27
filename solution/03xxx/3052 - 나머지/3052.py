import sys
input = sys.stdin.readline

find = set()

for _ in range(10):
    number = int(input())
    find.add(number % 42)

print(len(find))