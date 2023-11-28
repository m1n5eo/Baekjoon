def order(sentence):
    sentenceSplit = sentence.split(' ')
    temp = []
    for i in range(1, len(sentenceSplit)+1):
        for j in range(len(sentenceSplit)):
            for k in range(len(sentenceSplit[j])):
                if '1' <= sentenceSplit[j][k] and sentenceSplit[j][k] <= '9' and int(sentenceSplit[j][k]) == i:
                    temp.append(sentenceSplit[j])
                    break
    ans = ""
    for i in range(len(temp)):
        ans = ans + str(temp[i]) + ' '
    return ans.rstrip()