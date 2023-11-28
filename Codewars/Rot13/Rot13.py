def rot13(message):
    ans = ""
    for i in range(len(message)):
        if 'a' <= message[i] and message[i] <= 'z':
            if ord('a') <= ord(message[i])+13 and ord(message[i])+13 <= ord('z'):
                ans = ans + chr(ord(message[i])+13)
            else:
                ans = ans + chr(ord(message[i])-13)
        elif 'A' <= message[i] and message[i] <= 'Z':
            if ord('A') <= ord(message[i])+13 and ord(message[i])+13 <= ord('Z'):
                ans = ans + chr(ord(message[i])+13)
            else:
                ans = ans + chr(ord(message[i])-13)
        else:
            ans = ans + message[i]
    return ans