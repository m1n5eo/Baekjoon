import sys
input = sys.stdin.readline

word = input()[:-1]
s = set()

for i in range(len(word)):
    for j in range(i+1, len(word)+1):
        s.add(word[i:j])

print(len(s))