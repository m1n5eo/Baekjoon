def duplicate_encode(word):
    ans = ""
    word = word.lower()
    for i in range(len(word)):
        if word.count(word[i]) == 1:
            ans = ans + '('
        else:
            ans = ans + ')'
    return ans