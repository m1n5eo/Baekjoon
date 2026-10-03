import sys
from heapq import heappush, heappop
input = sys.stdin.readline

t, n = map(int, input().split())
heap = []

for _ in range(n):
    id, time, priority = map(int, input().split())
    heappush(heap, [-priority, id, time])

for _ in range(t):
    if len(heap) == 0:
        break

    now = heappop(heap)
    
    print(now[1])

    now[0] += 1
    now[2] -= 1

    if now[2] != 0:
        heappush(heap, now)