import sys
input = sys.stdin.readline

MOD = 1000000007

def cal(a, b):
    rtn = [[0, 0], [0, 0]]

    for i in range(2):
        for j in range(2):
            for k in range(2):
                rtn[i][j] = (rtn[i][j] + a[i][k]*b[k][j]) % MOD
    
    return rtn

def expo(matrix, p):
    if p <= 1:
        return [[1, 1], [1, 0]] if p == 1 else [[1, 1], [1, 1]]
    else:
        e = expo(matrix, p//2)
        return cal(e, e) if p%2 == 0 else cal(cal(e, e), [[1, 1], [1, 0]])

n = int(input())
matrix = expo([[1, 1], [1, 0]], n-1)

print(matrix[0][0] % MOD)