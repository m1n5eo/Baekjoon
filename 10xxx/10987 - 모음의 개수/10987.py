import sys
input = sys.stdin.readline

words = input()[:-1]
cnt = 0

for word in words:
    if word == 'a' or word == 'e' or word == 'i' or word == 'o' or word == 'u':
        cnt += 1

print(cnt)