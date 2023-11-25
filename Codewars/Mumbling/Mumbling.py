def accum(s):
    ans = ""
    for i in range(len(s)):
        if 'a' <= s[i] and s[i] <= 'z':
            ans = ans + chr(ord(s[i])-32)
            for j in range(0, i):
                ans = ans + s[i]
        elif 'A' <= s[i] and s[i] <= 'Z':
            ans = ans + s[i]
            for j in range(0, i):
                ans = ans + chr(ord(s[i])+32)
        if i == len(s)-1:
            break
        ans = ans + '-'
    return ans