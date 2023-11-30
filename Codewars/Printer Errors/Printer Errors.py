def printer_error(s):
    cnt = 0
    for i in range(len(s)):
        if not('a' <= s[i] and s[i] <= 'm'):
            cnt = cnt + 1
    return str(cnt) + "/" + str(len(s))