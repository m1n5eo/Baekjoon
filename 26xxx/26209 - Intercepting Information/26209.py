import sys
input = sys.stdin.readline

l = list(map(int, input().split()))

for i in range(8):
    if l[i] != 0 and l[i] != 1:
        print("F")
        exit()

print("S")