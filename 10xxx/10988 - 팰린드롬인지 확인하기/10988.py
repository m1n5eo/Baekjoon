import sys
input = sys.stdin.readline

word = input()[:-1]
palindrome = True

for i in range(len(word) // 2):
    if word[i] != word[len(word) - i - 1]:
        palindrome = False
        break

print(1 if palindrome == True else 0)