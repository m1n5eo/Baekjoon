import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    word = input()[:-1]
    print(word[0], word[-1], sep="")