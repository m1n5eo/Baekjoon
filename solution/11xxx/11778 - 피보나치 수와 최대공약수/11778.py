import sys
input = sys.stdin.readline

MOD = 1000000007

def gcd(a, b):
    if b == 0: return a
    else: return gcd(b, a%b)

def mul(a, b):
    rtn = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                rtn[i][j] = (rtn[i][j] + a[i][k]*b[k][j]) % MOD
    return rtn

def expo(matrix, p):
    if p < 1: return [[1, 1], [1, 1]]
    elif p == 1: return [[1, 1], [1, 0]]
    else:
        e = expo(matrix, p//2)
        return mul(e, e) if p%2 == 0 else mul(mul(e, e), [[1, 1], [1, 0]])

def solve():
    n, m = map(int, input().split())
    return expo([[1, 1], [1, 0]], gcd(n, m)-1)[0][0] % MOD

if __name__ == '__main__':
    print(solve())