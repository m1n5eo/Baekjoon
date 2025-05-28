import sys
input = sys.stdin.readline

word = input()[:-1]
count = [-1 for _ in range(26)]

for i in range(len(word)):
    if count[ord(word[i]) - ord('a')] == -1:
        count[ord(word[i]) - ord('a')] = i

for i in range(26):
    print(count[i], end=" ")