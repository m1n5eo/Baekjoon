import sys
input = sys.stdin.readline

MAX = 55

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def dfs(x, y):
    baechu[x][y] = 2

    for k in range(4):
        nx = x+dx[k]
        ny = y+dy[k]

        if 0 <= nx and nx < m and 0 <= ny and ny < n:
            if baechu[nx][ny] == 1:
                dfs(nx, ny)

t = int(input())

for testcase in range(t):
    m, n, k = map(int, input().split())
    
    baechu = [[0 for _ in range(MAX)] for _ in range(MAX)]
    result = 0

    for _ in range(k):
        x, y = map(int, input().split())
        baechu[x][y] = 1
    
    for i in range(m):
        for j in range(n):
            if baechu[i][j] == 1:
                dfs(i, j)
                result += 1
    
    print(result)