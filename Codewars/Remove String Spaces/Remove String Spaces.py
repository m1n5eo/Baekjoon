def no_space(x):
    ans = ""
    for i in range(len(x)):
        if x[i] != ' ':
            ans = ans + x[i]
    return ans