def open_or_senior(data):
    ans = []
    for i in range(len(data)):
        if data[i][0] > 54 and data[i][1] > 7:
            ans.append("Senior")
        else:
            ans.append("Open")
    return ans