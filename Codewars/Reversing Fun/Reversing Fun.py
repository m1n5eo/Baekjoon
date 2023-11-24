def reverse_fun(string):
    ans = ""
    for i in range(0, len(string)//2):
        ans = ans + string[len(string)-1-i] + string[i]
    if len(string)%2 == 1:
        ans = ans + string[len(string)//2]
    return ans