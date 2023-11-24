def square_digits(num):
    k = str(num)
    ans = ""
    for i in range(len(k)):
        ans = ans + str(int(k[i])*int(k[i]))
    return int(ans)