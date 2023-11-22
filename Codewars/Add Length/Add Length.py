def add_length(str_):
    a = str_.split()
    for i in range(len(a)):
        a[i] = a[i] + " %d" %len(a[i])
    return a