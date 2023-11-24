def to_alternating_case(string):
    ans = ""
    for i in range(len(string)):
        if 'a' <= string[i] and string[i] <= 'z':
            ans = ans + string[i].upper()
        elif 'A' <= string[i] and string[i] <= 'Z':
            ans = ans + string[i].lower()
        else:
            ans = ans + string[i]
    return ans