def find_short(s):
    min = 1234567890
    cnt = 0
    for i in range(len(s)):
        if s[i] == ' ':
            if min > cnt:
                min = cnt
            cnt = 0
        else:
            cnt = cnt + 1
    if min > cnt:
        return cnt
    else:
        return min