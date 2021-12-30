def solution(array, commands):
    answer = []
    for i in range(len(commands)):
        temp = []
        for j in range(commands[i][0]-1, commands[i][1]):
            temp.append(array[j])
        temp.sort()
        answer.append(temp[commands[i][2]-1])
    return answer