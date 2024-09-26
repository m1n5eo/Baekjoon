import sys
input = sys.stdin.readline

MOD = 1000000007

t = int(input())

for tc in range(t):
    word = input()[:-1]

    result = 0
    cnt = 0

    for words in word:
        if words == 'a' or words == 'e' or words == 'i' or words == 'o' or words == 'u':
            result = (result*cnt)%MOD if result != 0 else result+1
            cnt = 1
        else:
            cnt += 1
    
    if result != 0:
        print(result)
    else:
        print(-1)