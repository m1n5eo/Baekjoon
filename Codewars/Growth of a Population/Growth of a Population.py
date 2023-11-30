import math

def nb_year(p0, percent, aug, p):
    cnt = 0
    while p0 < p:
        cnt = cnt + 1
        p0 = math.floor(p0 + p0*percent/100 + aug)
    return cnt