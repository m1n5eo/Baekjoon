def solution(s):
    ans = []
    if len(s)%2 == 0:
        for i in range(len(s)//2):
            ans.append(s[i*2]+s[i*2+1])
    elif len(s)%2 == 1:
        for i in range(len(s)//2):
            ans.append(s[i*2]+s[i*2+1])
        ans.append(s[len(s)-1]+'_')
    return ans