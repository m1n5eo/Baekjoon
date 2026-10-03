import sys
input = sys.stdin.readline

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

result = 111

def find(index):
    global result

    if index == len(cctv):
        count = 0

        for i in range(n):
            for j in range(m):
                if office[i][j] == 0:
                    count += 1
        
        result = min(result, count)
        return
    
    mode = office[cctv[index][0]][cctv[index][1]]
    
    if mode == 1:
        for k in range(4):
            queue = list()

            x = cctv[index][0]
            y = cctv[index][1]

            while True:
                nx = x+dx[k]
                ny = y+dy[k]

                if 0 <= nx and nx < n and 0 <= ny and ny < m:
                    if office[nx][ny] == 6:
                        break
                    elif office[nx][ny] == 0:
                        office[nx][ny] -= 1
                        queue.append([nx, ny])
                else:
                    break

                x = nx
                y = ny
            
            find(index+1)

            while queue:
                office[queue[0][0]][queue[0][1]] += 1
                queue.pop(0)
    elif mode == 2:
        for k in range(2):
            queue = list()

            x = cctv[index][0]
            y = cctv[index][1]

            while True:
                nx = x+dx[k]
                ny = y+dy[k]

                if 0 <= nx and nx < n and 0 <= ny and ny < m:
                    if office[nx][ny] == 6:
                        break
                    elif office[nx][ny] == 0:
                        office[nx][ny] -= 1
                        queue.append([nx, ny])
                else:
                    break

                x = nx
                y = ny

            x = cctv[index][0]
            y = cctv[index][1]

            while True:
                nx = x+dx[(k+2)%4]
                ny = y+dy[(k+2)%4]

                if 0 <= nx and nx < n and 0 <= ny and ny < m:
                    if office[nx][ny] == 6:
                        break
                    elif office[nx][ny] == 0:
                        office[nx][ny] -= 1
                        queue.append([nx, ny])
                else:
                    break

                x = nx
                y = ny
            
            find(index+1)

            while queue:
                office[queue[0][0]][queue[0][1]] += 1
                queue.pop(0)
    elif mode == 3:
        for k in range(4):
            queue = list()

            x = cctv[index][0]
            y = cctv[index][1]

            while True:
                nx = x+dx[k]
                ny = y+dy[k]

                if 0 <= nx and nx < n and 0 <= ny and ny < m:
                    if office[nx][ny] == 6:
                        break
                    elif office[nx][ny] == 0:
                        office[nx][ny] -= 1
                        queue.append([nx, ny])
                else:
                    break

                x = nx
                y = ny

            x = cctv[index][0]
            y = cctv[index][1]

            while True:
                nx = x+dx[(k+1)%4]
                ny = y+dy[(k+1)%4]

                if 0 <= nx and nx < n and 0 <= ny and ny < m:
                    if office[nx][ny] == 6:
                        break
                    elif office[nx][ny] == 0:
                        office[nx][ny] -= 1
                        queue.append([nx, ny])
                else:
                    break

                x = nx
                y = ny
            
            find(index+1)

            while queue:
                office[queue[0][0]][queue[0][1]] += 1
                queue.pop(0)
    elif mode == 4:
        for k in range(4):
            queue = list()

            x = cctv[index][0]
            y = cctv[index][1]

            while True:
                nx = x+dx[k]
                ny = y+dy[k]

                if 0 <= nx and nx < n and 0 <= ny and ny < m:
                    if office[nx][ny] == 6:
                        break
                    elif office[nx][ny] == 0:
                        office[nx][ny] -= 1
                        queue.append([nx, ny])
                else:
                    break

                x = nx
                y = ny

            x = cctv[index][0]
            y = cctv[index][1]

            while True:
                nx = x+dx[(k+1)%4]
                ny = y+dy[(k+1)%4]

                if 0 <= nx and nx < n and 0 <= ny and ny < m:
                    if office[nx][ny] == 6:
                        break
                    elif office[nx][ny] == 0:
                        office[nx][ny] -= 1
                        queue.append([nx, ny])
                else:
                    break

                x = nx
                y = ny

            x = cctv[index][0]
            y = cctv[index][1]

            while True:
                nx = x+dx[(k+2)%4]
                ny = y+dy[(k+2)%4]

                if 0 <= nx and nx < n and 0 <= ny and ny < m:
                    if office[nx][ny] == 6:
                        break
                    elif office[nx][ny] == 0:
                        office[nx][ny] -= 1
                        queue.append([nx, ny])
                else:
                    break

                x = nx
                y = ny
            
            find(index+1)

            while queue:
                office[queue[0][0]][queue[0][1]] += 1
                queue.pop(0)
    if mode == 5:
        queue = list()

        for k in range(4):
            x = cctv[index][0]
            y = cctv[index][1]

            while True:
                nx = x+dx[k]
                ny = y+dy[k]

                if 0 <= nx and nx < n and 0 <= ny and ny < m:
                    if office[nx][ny] == 6:
                        break
                    elif office[nx][ny] == 0:
                        office[nx][ny] -= 1
                        queue.append([nx, ny])
                else:
                    break

                x = nx
                y = ny
            
        find(index+1)

        while queue:
            office[queue[0][0]][queue[0][1]] += 1
            queue.pop(0)

n, m = map(int, input().split())
office = [list(map(int, input().split())) for _ in range(n)]

cctv = list()

for i in range(n):
    for j in range(m):
        if 0 < office[i][j] and office[i][j] < 6:
            cctv.append([i, j])

find(0)

print(result)