def generate_hashtag(s):
    ans = ""
    sSplit = s.lower().split()
    for i in range(len(sSplit)):
        ans = ans + sSplit[i][0].upper() + sSplit[i][1:]
    if len(ans) > 139 or len(ans) == 0:
        return False
    else:
        return '#' + ans