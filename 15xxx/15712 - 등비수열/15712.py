import sys
input = sys.stdin.readline

def cal(a, b, mod):
    rtn = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                rtn[i][j] = (rtn[i][j] + a[i][k]*b[k][j]) % mod
    return rtn

def solve(matrix, n, a, r, mod):
    if n == 0: return [[1, 1], [1, 1]]
    elif n == 1: return [[r, 0], [a, 1]]

    m = solve(matrix, n//2, a, r, mod)
    if n%2 == 0: return cal(m, m, mod)
    else: return cal(cal(m, m, mod), [[r, 0], [a, 1]], mod)

if __name__ == '__main__':
    a, r, n, mod = map(int, input().split())
    matrix = solve([[r, 0], [a, 1]], n, a, r, mod)
    print(matrix[1][0] % mod)