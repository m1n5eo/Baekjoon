def xo(s):
    x_cnt = 0
    o_cnt = 0
    for i in range(len(s)):
        if s[i] == 'x' or s[i] == 'X':
            x_cnt = x_cnt + 1
        elif s[i] == 'o' or s[i] == 'O':
            o_cnt = o_cnt + 1
    if x_cnt == o_cnt:
        return True
    else:
        return False