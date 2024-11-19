import sys
input = sys.stdin.readline

baby = list()
shark = [2, 0]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

def eat(x, y):
    sea[x][y] = 0
    shark[1] += 1

    if shark[0] == shark[1]:
        shark[0] += 1
        shark[1] = 0

def bfs(x, y):
    global baby

    queue = [[x, y, 0]]
    visit = [[False for _ in range(n)] for _ in range(n)]

    visit[x][y] = True

    while queue:
        size = len(queue)
        possible = list()

        for _ in range(size):
            now = queue.pop(0)

            for k in range(4):
                next = [now[0]+dx[k], now[1]+dy[k], now[2]+1]

                if 0 <= next[0] and next[0] < n and 0 <= next[1] and next[1] < n:
                    if visit[next[0]][next[1]] == False:
                        if sea[next[0]][next[1]] == 0:
                            visit[next[0]][next[1]] = True
                            queue.append(next)
                        elif sea[next[0]][next[1]] == shark[0]:
                            visit[next[0]][next[1]] = True
                            queue.append(next)
                        elif sea[next[0]][next[1]] < shark[0]:
                            possible.append(next)
                        elif sea[next[0]][next[1]] > shark[0]:
                            continue
        
        if possible:
            possible.sort()
            eat(possible[0][0], possible[0][1])
            baby = [possible[0][0], possible[0][1]]
            return possible[0][2]
    
    return -1

if __name__ == '__main__':
    n = int(input())
    sea = [list(map(int, input().split())) for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if sea[i][j] == 9:
                baby = [i, j]
                sea[i][j] = 0
    
    time = 0

    while True:
        t = bfs(baby[0], baby[1])

        if t == -1:
            break
        else:
            time += t
    
    print(time)