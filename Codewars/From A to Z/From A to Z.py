def gimme_the_letters(sp):
    arr = sp.split("-")
    ans = ""
    for i in range(ord(arr[0]), ord(arr[1])+1):
        ans = ans + chr(i)
    return ans