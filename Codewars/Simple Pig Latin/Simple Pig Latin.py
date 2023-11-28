def pig_it(text):
    ans = ""
    textSplit = text.split()
    for i in range(len(textSplit)):
        if len(textSplit[i]) == 1 and not('a' <= textSplit[i].lower() and textSplit[i].lower() <= 'z'):
            ans = ans + textSplit[i] + ' '
        else:
            ans = ans + textSplit[i][1:len(textSplit[i])] + textSplit[i][0] + 'ay '
    return ans.rstrip()