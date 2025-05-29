import sys
input = sys.stdin.readline

def check(word):
    count = [0 for _ in range(26)]

    for i in range(len(word)):
        if count[ord(word[i]) - ord('a')] == 0:
            count[ord(word[i]) - ord('a')] += 1
        elif count[ord(word[i]) - ord('a')] != 0 and word[i] != word[i-1]:
            return 0
    
    return 1

n = int(input())
result = 0

for _ in range(n):
    word = input()[:-1]
    result += check(word)

print(result)