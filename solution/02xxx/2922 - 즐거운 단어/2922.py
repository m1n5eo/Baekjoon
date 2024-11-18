import sys
input = sys.stdin.readline

aeiou = ['A', 'E', 'I', 'O', 'U']
not_aeiou = ['B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z']

result = 0

def backtracking(index, mo, ja, check, now):
    global result, str

    if mo >= 3 or ja >= 3:
        return

    if index == len(str):
        if check == True:
            result += now
        return

    if str[index] == '_':
        backtracking(index+1, mo+1, 0, check, now*len(aeiou))
        backtracking(index+1, 0, ja+1, check, now*(len(not_aeiou)-1))
        backtracking(index+1, 0, ja+1, True, now*1)
    elif str[index] == 'L':
        backtracking(index+1, 0, ja+1, True, now)
    elif str[index] in aeiou:
        backtracking(index+1, mo+1, 0, check, now)
    elif str[index] not in aeiou:
        backtracking(index+1, 0, ja+1, check, now)

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