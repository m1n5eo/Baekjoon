import sys
input = sys.stdin.readline

MOD = 10007

def solve():
    word = input()[:-1]
    n = len(word)
    dp = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n-i):
            a, b = j, j+i
            if a == b: dp[a][b] = 1
            elif a == b+1:
                dp[a][b] = 2
                if word[a] == word[b]: dp[a][b] += 1
            else:
                dp[a][b] = dp[a][b-1] + dp[a+1][b] - dp[a+1][b-1]
                if word[a] == word[b]: dp[a][b] += dp[a+1][b-1]+1

    return dp[0][-1] % MOD

if __name__ == '__main__':
    print(solve())