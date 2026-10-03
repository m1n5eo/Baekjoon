import sys
input = sys.stdin.readline

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x, y = find(x), find(y)

    if x > y:
        parent[x] = y
    else:
        parent[y] = x

def same(x, y):
    x, y = find(x), find(y)
    return True if x == y else False

def index(x, y):
    return x*m+y+1

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())
move = [[0 for _ in range(m)] for _ in range(n)]
visit = [[False for _ in range(m)] for _ in range(n)]
parent = [i for i in range(n*m+1)]

for i in range(n):
    str = input()[:-1]

    for j in range(m):
        if str[j] == 'N':
            move[i][j] = 0
        elif str[j] == 'E':
            move[i][j] = 1
        elif str[j] == 'S':
            move[i][j] = 2
        elif str[j] == 'W':
            move[i][j] = 3

for i in range(n):
    for j in range(m):
        if visit[i][j] == False:
            x, y = i, j

            while visit[x][y] == False:
                visit[x][y] = True
                nx, ny = x+dx[move[x][y]], y+dy[move[x][y]]
                union(index(x, y), index(nx, ny))
                x, y = nx, ny

result = 0

for i in range(n):
    for j in range(m):
        if same(0, index(i, j)) == False:
            result += 1
            union(0, index(i, j))
    
print(result)