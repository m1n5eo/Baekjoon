def repeating_fractions(numerator,denominator):
    temp = ""
    ans = ""
    idx = 0
    for i in range(len(str(numerator/denominator))):
        if idx:
            temp = temp + str(numerator/denominator)[i]
        elif idx == 0 and str(numerator/denominator)[i] == '.':
            ans = ans + '.'
            idx = i
        else:
            ans = ans + str(numerator/denominator)[i]
    for i in range(len(temp)):
        if i-1 >= 0 and temp[i-1] == temp[i]:
            continue
        else:
            if i+1 < len(temp) and temp[i] == temp[i+1]:
                ans = ans + '(' + temp[i] + ')'
            else:
                ans = ans + temp[i]
    return ans