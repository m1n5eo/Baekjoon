import sys
input = sys.stdin.readline

INF = 2000000001
MAX = 101

dp = [[0 for _ in range(MAX)] for _ in range(MAX)]

def gcd(a, b):
    if b == 0: return a
    else: return gcd(b, a%b)

def init():
    for i in range(MAX): dp[i][0] = 1
    for j in range(MAX): dp[0][j] = 1
    for i in range(1, MAX):
        for j in range(1, MAX):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]

def traceback(zero, one, left, right, now):
    # print(zero, one, left, right, now)
    if zero == 0 and one == 0: return ""
    elif one == 0: return "a" + traceback(zero-1, one, left, right, now)
    elif zero == 0: return "z" + traceback(zero, one-1, left, right, now)

    g = gcd(zero, one)
    k = (right-left+1)//((zero+one)//g)
    mid = left + (zero//g)*k - 1

    if left <= now and now <= mid: return "a" + traceback(zero-1, one, left, mid, now)
    elif mid < now and now <= right: return "z" + traceback(zero, one-1, mid+1, right, now)

def solve():
    n, m, k = map(int, input().split())
    if dp[n][m] < k: return -1
    return traceback(n, m, 1, dp[n][m], k)

if __name__ == '__main__':
    init()
    print(solve())