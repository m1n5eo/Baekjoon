def friend(x):
    ans = []
    for i in range(len(x)):
        if len(x[i]) == 4:
            ans.append(x[i])
    return ans