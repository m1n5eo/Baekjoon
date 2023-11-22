def flick_switch(lst):
    prt = [False] * len(lst)
    sw = 0
    for i in range(len(lst)):
        if lst[i] == 'flick':
            if sw == 0:
                prt[i] = False
                sw = 1
            elif sw == 1:
                prt[i] = True
                sw = 0
        elif lst[i] != 'flick':
            if sw == 0:
                prt[i] = True
            elif sw == 1:
                prt[i] = False
    return prt