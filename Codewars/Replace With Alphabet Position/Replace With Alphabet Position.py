def alphabet_position(text):
    ans = ""
    text = text.lower()
    for i in range(len(text)):
        if 'a' <= text[i] and text[i] <= 'z':
            ans = ans + str(ord(text[i])-96) + ' '
    return ans.rstrip(' ')