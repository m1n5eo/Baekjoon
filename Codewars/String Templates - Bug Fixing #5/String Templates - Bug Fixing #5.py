def build_string(*args):
    a = ""
    for i in range(len(args)):
        a = a + "{0}".format(args[i])
        if i != len(args)-1:
            a = a + ", "
    return "I like {0}!".format(a)