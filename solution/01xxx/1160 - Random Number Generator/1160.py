import sys
input = sys.stdin.readline

def cal(a, b, mod):
    rtn = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                rtn[i][j] = (rtn[i][j] + a[i][k]*b[k][j]) % mod
    return rtn

def expo(matrix, n, a, r, mod):
    if n == 0: return [[1, 1], [1, 1]]
    elif n == 1: return [[r, 0], [a, 1]]

    m = expo(matrix, n//2, a, r, mod)
    if n%2 == 0: return cal(m, m, mod)
    else: return cal(cal(m, m, mod), [[r, 0], [a, 1]], mod)

def solve():
    mod, a, c, x, n, g = map(int, input().split())
    matrix = expo([[a, 0], [c, 1]], n, c, a, mod)
    return ((matrix[0][0]*x + matrix[1][0]) % mod) % g

if __name__ == '__main__':
    print(solve())