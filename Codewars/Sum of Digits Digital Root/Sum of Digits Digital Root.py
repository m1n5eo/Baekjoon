def hap(num):
    ans = 0
    while num:
        ans = ans + num%10
        num = num//10
    return ans

def digital_root(n):
    while hap(n) > 9:
        n = hap(n)
    return hap(n)