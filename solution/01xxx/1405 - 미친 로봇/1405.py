import sys
input = sys.stdin.readline

MAX = 33

visit = [[False for _ in range(MAX)] for _ in range(MAX)]

def dfs(cnt, e, w, s, n, now, x, y):
    if cnt == 0:
        return now

    ret = 0
    if visit[x-1][y] == False:
        visit[x-1][y] = True
        ret += dfs(cnt-1, e, w, s, n, now*(e/100), x-1, y)
        visit[x-1][y] = False
    if visit[x+1][y] == False:
        visit[x+1][y] = True
        ret += dfs(cnt-1, e, w, s, n, now*(w/100), x+1, y)
        visit[x+1][y] = False
    if visit[x][y+1] == False:
        visit[x][y+1] = True
        ret += dfs(cnt-1, e, w, s, n, now*(s/100), x, y+1)
        visit[x][y+1] = False
    if visit[x][y-1] == False:
        visit[x][y-1] = True
        ret += dfs(cnt-1, e, w, s, n, now*(n/100), x, y-1)
        visit[x][y-1] = False
    return ret

def solve():
    cnt, e, w, s, n = map(int, input().split())
    visit[15][15] = True
    return dfs(cnt, e, w, s, n, 1, 15, 15)

if __name__ == '__main__':
    print(solve())