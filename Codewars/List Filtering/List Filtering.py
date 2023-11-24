def filter_list(l):
    ans = []
    for i in range(len(l)):
        if str(type(l[i])) != "<class 'str'>":
            ans.append(l[i])
    return ans