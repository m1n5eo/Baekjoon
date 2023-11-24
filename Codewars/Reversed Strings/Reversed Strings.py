def solution(string):
    ans = ""
    for i in range(len(string)-1, -1, -1):
        ans = ans + string[i]
    return ans