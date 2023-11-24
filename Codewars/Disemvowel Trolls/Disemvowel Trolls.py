def disemvowel(string_):
    ans = ""
    for i in range(len(string_)):
        if string_[i] == 'a' or string_[i] == 'A':
            continue
        elif string_[i] == 'e' or string_[i] == 'E':
            continue
        elif string_[i] == 'i' or string_[i] == 'I':
            continue
        elif string_[i] == 'o' or string_[i] == 'O':
            continue
        elif string_[i] == 'u' or string_[i] == 'U':
            continue
        else:
            ans = ans + string_[i]
    return ans