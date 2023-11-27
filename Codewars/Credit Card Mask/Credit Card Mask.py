def maskify(cc):
    ans = ""
    for i in range(len(cc)):
        if len(cc)-4 > i:
            ans = ans + "#"
        else:
            ans = ans + cc[i]
    return ans