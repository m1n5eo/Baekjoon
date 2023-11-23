def fake_bin(x):
    sum = 0
    for i in range(len(x)):
        if ord(x[i]) < ord('5'):
            sum = sum*10 + 0
        else:
            sum = sum*10 + 1
    return str(sum).zfill(len(x))