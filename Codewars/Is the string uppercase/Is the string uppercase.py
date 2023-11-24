def is_uppercase(inp):
    for i in range(len(inp)):
        if 'a' <= inp[i] and inp[i] <= 'z':
            return False
    return True