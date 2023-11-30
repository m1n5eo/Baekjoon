def dig_pow(n, p):
    temp = 0
    for i in range(len(str(n))):
        temp = temp + int(str(n)[i])**p
        p = p + 1
    if temp%n != 0:
        return -1
    else:
        return temp/n