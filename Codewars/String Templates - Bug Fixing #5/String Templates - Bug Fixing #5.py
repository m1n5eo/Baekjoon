def build_string(*args):
    a = ""
    for i in range(len(args)):
        a = a + "{0}".format(args[i])
        if i+1 != len(args):
            a = a + ", "
    return "I like {0}!".format(a)