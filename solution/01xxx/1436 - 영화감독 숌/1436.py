import sys
input = sys.stdin.readline

n = int(input())
count = 0
index = 1

while n != count:
    index += 1

    if "666" in str(index):
        count += 1

print(index)