def count_sheeps(sheep):
    cnt = 0
    for i in range(len(sheep)):
        if sheep[i] == True:
            cnt = cnt+1
    return cnt