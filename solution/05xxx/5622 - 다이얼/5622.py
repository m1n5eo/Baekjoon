import sys
input = sys.stdin.readline

word = input()[:-1]
phone = [3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10]
sum = 0

for i in range(len(word)):
    sum += phone[ord(word[i]) - ord('A')]

print(sum)