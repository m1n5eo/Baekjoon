def encode(message, key):
    arr = []
    cnt = 0
    while True:
        if key//(10**cnt) == 0:
            break
        cnt = cnt + 1
    for i in range(len(message)):
        arr.append(ord(message[i])-96 + (key//10**((cnt-i-1)%cnt))%10)
    return arr