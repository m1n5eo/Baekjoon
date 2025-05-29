import sys
input = sys.stdin.readline

word = input()[:-1]
count = [0 for _ in range(26)]
result = list()

for w in word:
    if 'a' <= w and w <= 'z':
        count[ord(w) - ord('a')] += 1
    elif 'A' <= w and w <= 'Z':
        count[ord(w) - ord('A')] += 1

for i in range(26):
    if count[i] == max(count):
        result.append(i)

print(chr(ord('A') + result[0]) if len(result) == 1 else '?')