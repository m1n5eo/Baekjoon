def descending_order(num):
    n = []
    while num > 0:
        n.append(num%10)
        num = num // 10
    if len(n) == 0:
        n.append(0)
    n.sort(reverse=True)
    ans = 0
    for i in range(len(n)):
        ans = ans*10 + n[i]
    return ans