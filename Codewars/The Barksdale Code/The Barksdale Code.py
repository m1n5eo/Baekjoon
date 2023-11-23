def decode(strng):
    ans = 0
    for i in range(len(strng)):
        if strng[i] == '0' or strng[i] == '5':
            ans = ans*10 + 53-ord(strng[i])
        else:
            ans = ans*10 + 58-ord(strng[i])
    return str(ans).zfill(len(strng))