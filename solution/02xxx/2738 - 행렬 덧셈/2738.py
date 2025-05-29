import sys
input = sys.stdin.readline

n, m = map(int, input().split())

matrix_A = [list(map(int, input().split())) for _ in range(n)]
matrix_B = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    for j in range(m):
        print(matrix_A[i][j] + matrix_B[i][j], end=" ")
    print()