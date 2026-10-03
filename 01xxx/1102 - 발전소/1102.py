import sys
input = sys.stdin.readline

INF = 1234567890

def solve():
    n = int(input())
    cost = [list(map(int, input().split())) for _ in range(n)]
    status = input()[:-1]
    p = int(input())

    b = ""
    cnt = 0
    for s in status:
        if s == 'Y':
            b = '1' + b
            cnt += 1
        elif s == 'N':
            b = '0' + b

    if cnt >= p: return 0
    elif int(b, 2) == 0: return -1
    
    dp = [INF for _ in range(pow(2, n))]
    dp[int(b, 2)] = 0

    for i in range(int(b, 2)+1, pow(2, n)):
        b = str(bin(i))[2:]
        b = '0'*(n-len(b)) + b
        for j in range(n):
            if b[j] == '1':
                for k in range(n):
                    if j != k and b[k] == '1':
                        dp[i] = min(dp[i], dp[i-pow(2, n-j-1)] + cost[n-k-1][n-j-1])

    ret = INF
    for i in range(pow(2, n)):
        b = str(bin(i))[2:]
        count = 0
        for bb in b:
            if bb == '1':
                count += 1
        if count == p:
            ret = min(ret, dp[i])
    return ret if ret != INF else -1

if __name__ == '__main__':
    print(solve())