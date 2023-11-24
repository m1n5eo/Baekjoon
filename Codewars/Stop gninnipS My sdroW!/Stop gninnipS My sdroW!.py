def spin_words(sentence):
    sp = sentence.split(' ')
    ans = ""
    for i in range(len(sp)):
        if len(sp[i]) < 5:
            ans = ans + sp[i]
        else:
            ans = ans + sp[i][::-1]
        if i != len(sp)-1:
            ans = ans + ' '
    return ans