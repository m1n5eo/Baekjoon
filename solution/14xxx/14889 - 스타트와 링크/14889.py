import sys
input = sys.stdin.readline

MAX = 1234567890

def status(start, link, cnt):
    global n, score, result

    if n == cnt:
        stat1 = 0
        stat2 = 0

        for i in range(n//2):
            for j in range(n//2):
                stat1 += score[start[i]][start[j]]
                stat2 += score[link[i]][link[j]]
        
        result = min(result, abs(stat1-stat2))

    if len(start) < n//2:
        status(start + [cnt], link, cnt+1)
    if len(link) < n//2:
        status(start, link + [cnt], cnt+1)

n = int(input())
score = [list(map(int, input().split())) for _ in range(n)]
result = MAX

status([], [], 0)

print(result)