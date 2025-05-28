import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    re, word = input()[:-1].split()
    
    for i in range(len(word)):
        print(word[i] * int(re), end="")
    print()