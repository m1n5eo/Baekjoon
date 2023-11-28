def persistence(n):
    cnt = 0
    n = str(n)
    while True:
        if len(n) == 1:
            break
        temp = 1
        cnt = cnt + 1
        for i in range(len(n)):
            temp = temp * int(n[i])
        n = str(temp)
    return cnt