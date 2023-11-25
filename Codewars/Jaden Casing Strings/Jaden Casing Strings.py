def to_jaden_case(string):
    ans = ""
    for i in range(len(string)):
        if (i == 0 or (i != 0 and string[i-1] == ' ')) and 'a' <= string[i] and string[i] <= 'z':
            ans = ans + chr(ord(string[i])-32)
        elif i != 0 and string[i-1] != ' ' and 'A' <= string[i] and string[i] <= 'Z':
            ans = ans + chr(ord(string[i])+32)
        else:
            ans = ans + string[i]
    return ans