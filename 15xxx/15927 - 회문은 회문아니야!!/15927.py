import sys
input = sys.stdin.readline

def solve():
    word = input()[:-1]
    count = 0
    left, right = 0, len(word)-1
    while left <= right:
        if word[left] != word[right]: return len(word)
        if word[0] == word[left]: count += 1
        if word[0] == word[right]: count += 1
        left += 1
        right -= 1
    if count > len(word): count = len(word)
    if count == len(word): return -1
    else: return len(word)-1

if __name__ == '__main__':
    print(solve())