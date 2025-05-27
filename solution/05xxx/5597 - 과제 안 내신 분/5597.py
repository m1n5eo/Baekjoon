import sys
input = sys.stdin.readline

count = [False for _ in range(31)]

for _ in range(28):
    n = int(input())
    count[n] = True

for i in range(1, 31):
    if count[i] == False:
        print(i)