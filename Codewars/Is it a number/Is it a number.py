def is_digit(s):
    dot = 0
    space = 0
    num = 0
    minus = 0
    for i in range(len(s)):
        if not(s[i] == '-' or s[i] == '.' or s[i] == ' ') and not(ord('0') <= ord(s[i]) and ord(s[i]) <= ord('9')):
            return False
        elif s[i] == '-' and minus == 1:
            return False
        elif s[i] == ' ' and space == 1:
            return False
        elif s[i] == '.' and dot == 1:
            return False
        elif s[i] == '-'and num == 1:
            return False
        
        if minus == 0 and s[i] == '-':
            minus = 1
        if space == 0 and s[i] != ' ':
            space = 1
        if dot == 0 and s[i] == '.':
            dot = 1
        if ord('0') <= ord(s[i]) and ord(s[i]) <= ord('9'):
            num = 1
    if num == 0:
        return False
    else:
        return True