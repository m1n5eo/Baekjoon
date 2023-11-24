def evaluate(equation):
    sp = equation.split()
    ans = int(sp[0])
    for i in range(2, len(sp), 2):
        k = int(sp[i])
        if k == 0:
            return None
        ans = (ans+k) + (ans-k) + (ans*k) + (ans//k)
    return ans