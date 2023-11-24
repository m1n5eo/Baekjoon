def is_square(n):
    if n < 0:
        return False
    elif n == 0:
        return True
    
    for i in range(n//2+1):
        if i*i == n:
            return True
    return False