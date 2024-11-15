import sys
input = sys.stdin.readline

n = int(input())
num = [0] + list(map(int, input().split()))

dp = [[0 for _ in range(2)] for _ in range(n+1)]

for i in range(1, n+1):
    start = i
    end = i
    cnt = -1

    while True:
        if 1 <= start and end <= n and num[start] == num[end]:
            start -= 1
            end += 1
            cnt += 1
        else:
            break
    
    dp[i][0] = cnt

    start = i
    end = i+1
    cnt = -1

    while True:
        if 1 <= start and end <= n and num[start] == num[end]:
            start -= 1
            end += 1
            cnt += 1
        else:
            break
    
    dp[i][1] = cnt

m = int(input())

for _ in range(m):
    s, e = map(int, input().split())
    print(1 if dp[(s+e)//2][(s+e)%2] >= (s+e)//2-s else 0)