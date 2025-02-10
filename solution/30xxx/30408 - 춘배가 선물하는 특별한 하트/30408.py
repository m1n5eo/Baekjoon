import sys
input = sys.stdin.readline

n, m = map(int, input().split())
result = False
bfs = list()
s = set()

bfs.append(n)
s.add(n)

while len(bfs) != 0:
    now = bfs.pop(0)

    if now == m:
        result = True
        break

    if now%2 == 0:
        if now // 2 >= m and now // 2 not in s:
            bfs.append(now // 2)
            s.add(now // 2)
    elif now%2 == 1:
        if now // 2 >= m and now // 2 not in s:
            bfs.append(now // 2)
            s.add(now // 2)
        if now // 2 + 1 >= m and now // 2 + 1 not in s:
            bfs.append(now // 2 + 1)
            s.add(now // 2 + 1)
          
print("YES" if result == True else "NO")