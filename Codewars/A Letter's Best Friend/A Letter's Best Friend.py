def best_friend(txt, a, b):
    if a == b:
        return False
    word = txt.split()
    for i in range(len(word)):
        for j in range(len(word[i])):
            if word[i][j] == a and len(word[i]) == j+1:
                return False
            elif word[i][j] == a and word[i][j+1] != b:
                return False
    return True