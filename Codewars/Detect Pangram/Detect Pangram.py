def is_pangram(s):
    arr = [0]*26
    s = s.lower()
    for i in range(len(s)):
        if 'a' <= s[i] and s[i] <= 'z':
            arr[ord(s[i])-97] = arr[ord(s[i])-97] + 1
    for i in range(26):
        if arr[i] == 0:
            return False
    return True