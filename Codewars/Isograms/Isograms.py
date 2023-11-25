def is_isogram(string):
    for i in range(len(string)):
        for j in range(i+1, len(string)):
            if string[i] == string[j] or ord(string[i]) == ord(string[j])+32 or ord(string[i]) == ord(string[j])-32:
                return False
    return True