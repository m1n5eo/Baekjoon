def solution(n, lost, reserve):
    lostReal = set(lost)-set(reserve);
    reserveReal = set(reserve)-set(lost);
    for i in reserveReal:
        if i-1 in lostReal:
            lostReal.remove(i-1)
        elif i+1 in lostReal:
            lostReal.remove(i+1)
    answer = n-len(lostReal)
    return answer