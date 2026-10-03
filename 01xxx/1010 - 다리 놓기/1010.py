import sys
input = sys.stdin.readline

setting = [[0 for j in range(33)] for i in range(33)]

for i in range(1, 31):
    setting[1][i] = i

for i in range(2, 31):
    for j in range(1, 31):
        setting[i][j] = setting[i-1][j-1] + setting[i][j-1]

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    print(setting[n][m])