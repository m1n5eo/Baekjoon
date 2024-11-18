import sys
input = sys.stdin.readline

aeiou = ['A', 'E', 'I', 'O', 'U']
result = 0

def backtracking(index, mo, ja, check, now):
    global result, str

    if mo >= 3 or ja >= 3:
        return
    elif index == len(str):
        if check == True:
            result += now
        return

    if str[index] == '_':
        backtracking(index+1, mo+1, 0, check, now*len(aeiou))
        backtracking(index+1, 0, ja+1, check, now*(25-len(aeiou)))
        backtracking(index+1, 0, ja+1, True, now)
    else:
        backtracking(index+1, mo+1, 0, check, now) if str[index] in aeiou else backtracking(index+1, 0, ja+1, True if str[index] == 'L' else check, now)

if __name__ == '__main__':
    str = list(input())[:-1]

    for i in range(len(str)):
        if str[i] == 'L':
            backtracking(0, 0, 0, True, 1)
            break
        if i == len(str)-1:
            backtracking(0, 0, 0, False, 1)
            break

    print(result)