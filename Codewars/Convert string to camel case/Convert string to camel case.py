def to_camel_case(text):
    ans = ""
    for i in range(len(text)):
        if text[i] == '-' or text[i] == '_':
            continue
        elif (text[i-1] == '-' or text[i-1] == '_') and 'a' <= text[i] and text[i] <= 'z':
            ans = ans + chr(ord(text[i])-32)
        else:
            ans = ans + text[i]
    return ans