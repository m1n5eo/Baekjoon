def decode(message):
    prt = 'a'
    for i in range(len(message)):
        if 'a' <= message[i] and message[i] <= 'z':
            219
            prt = prt + chr(219-ord(message[i]))
        else:
            prt = prt + message[i]
    return prt[1:]