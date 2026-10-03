import sys
input = sys.stdin.readline

n = int(input())

for i in range(1, n+1):
    name = input()[:-1]
    print(i, ". ", name, sep="")