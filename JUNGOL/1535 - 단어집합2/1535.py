save = []

while True:
    temp = input().split(' ')
    if temp[0] == 'END':
        break
    saveLen = len(save)
    if saveLen == 0:
        save = temp
        for i in range(len(save)):
            print(save[i], end=" ")
        print()
        continue
    for i in range(len(temp)):
        for j in range(saveLen):
            if save[j] == temp[i]:
                break
            if j == saveLen-1:
                save.append(temp[i])
    for i in range(len(save)):
        print(save[i], end=" ")
    print()