import sys
input = sys.stdin.readline

MOD = 1000

def calculate(a, b):
    rtn = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            for k in range(n):
                rtn[i][j] = (rtn[i][j] + a[i][k]*b[k][j]) % MOD

    return rtn


def expo(matrix, p):
    if p <= 1:
        return matrix if p == 1 else [[1, 1], [1, 1]]
    else:
        e = expo(matrix, p//2)
        return calculate(e, e) if p%2 == 0 else calculate(calculate(e, e), matrix)

n, k = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]

result = expo(matrix, k)

for i in range(n):
    for j in range(n):
        print(result[i][j] % MOD, end=" ")
    print()