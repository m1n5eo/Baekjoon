def count_bits(n):
    cnt = 0
    while n:
        if n%2 == 1:
            cnt = cnt + 1
        n = n//2
    return cnt