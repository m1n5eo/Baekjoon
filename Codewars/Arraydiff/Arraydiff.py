def array_diff(a, b):
    ans = []
    for i in range(len(a)):
        for j in range(len(b)):
            if a[i] == b[j]:
                break
            elif j == len(b)-1:
                ans.append(a[i])
        if len(b) == 0:
            ans.append(a[i])
    return ans