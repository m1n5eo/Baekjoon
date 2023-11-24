def get_count(sentence):
    cnt = 0
    for i in range(len(sentence)):
        if sentence[i] == 'a' or sentence[i] == 'e' or sentence[i] == 'i' or sentence[i] == 'o' or sentence[i] == 'u':
            cnt = cnt + 1
    return cnt