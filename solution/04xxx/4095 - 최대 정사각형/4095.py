import sys
input = sys.stdin.readline

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0: break
    matrix = [list(map(int, input().split())) for _ in range(n)]
    res = 0
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0: continue
            elif i == 0 or j == 0: matrix[i][j] = 1
            elif matrix[i-1][j-1] != 0 and matrix[i-1][j] != 0 and matrix[i][j-1] != 0: matrix[i][j] = min(matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]) + 1
            res = max(res, matrix[i][j])
    print(res)