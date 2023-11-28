def is_valid_walk(walk):
    if len(walk) != 10:
        return False
    up_down = 0
    left_right = 0
    for i in range(len(walk)):
        if walk[i] == 'n':
            up_down = up_down + 1
        elif walk[i] == 's':
            up_down = up_down - 1
        elif walk[i] == 'e':
            left_right = left_right + 1
        elif walk[i] == 'w':
            left_right = left_right - 1
    if up_down == 0 and left_right == 0:
        return True
    else:
        return False