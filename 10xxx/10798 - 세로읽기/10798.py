import sys
input = sys.stdin.readline

word = [input()[:-1] for _ in range(5)]
m = 0

for i in range(5):
    m = max(m, len(word[i]))

for j in range(m):
    for i in range(5):
        if j < len(word[i]):
            print(word[i][j], end="")