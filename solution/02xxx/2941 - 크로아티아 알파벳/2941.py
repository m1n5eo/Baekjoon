import sys
input = sys.stdin.readline

word = input()[:-1]
index = 0
count = 0

while index < len(word):
    if index+1 < len(word) and word[index] == 'c' and word[index+1] == '=':
        index += 2
        count += 1
    elif index+1 < len(word) and word[index] == 'c' and word[index+1] == '-':
        index += 2
        count += 1
    elif index+2 < len(word) and word[index] == 'd' and word[index+1] == 'z' and word[index+2] == '=':
        index += 3
        count += 1
    elif index+1 < len(word) and word[index] == 'd' and word[index+1] == '-':
        index += 2
        count += 1
    elif index+1 < len(word) and word[index] == 'l' and word[index+1] == 'j':
        index += 2
        count += 1
    elif index+1 < len(word) and word[index] == 'n' and word[index+1] == 'j':
        index += 2
        count += 1
    elif index+1 < len(word) and word[index] == 's' and word[index+1] == '=':
        index += 2
        count += 1
    elif index+1 < len(word) and word[index] == 'z' and word[index+1] == '=':
        index += 2
        count += 1
    else:
        index += 1
        count += 1

print(count)