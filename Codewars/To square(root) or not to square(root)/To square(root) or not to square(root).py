import math

def square_or_square_root(arr):
    prt = [0.0] * len(arr)
    for i in range(len(arr)):
        if math.sqrt(arr[i]).is_integer():
            prt[i] = math.sqrt(arr[i])
        else:
            prt[i] = arr[i]*arr[i]
    return prt