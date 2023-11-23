def uni_total(s):
    sum = 0
    for i in range(len(s)):
        sum = sum + ord(s[i])
    return sum