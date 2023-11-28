def longest(a1, a2):
    new = a1 + a2
    arr = [0]*26
    for i in range(len(new)):
        arr[ord(new[i])-97] = 1
    ans = ""
    for i in range(26):
        if arr[i]:
            ans = ans + chr(i+97)
    return ans