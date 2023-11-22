def sum_mul(n, m):
    if n <= 0 or m <= 0:
        return 'INVALID'
    
    sum = 0
    for i in range(n, m, n):
        sum = sum + i
    return sum