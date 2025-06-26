import sys
input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    next = [int(input()) for _ in range(n)]
    now, count = 0, 0

    while(True):
        now = next[now]
        count += 1

        if now == k:
            return count
        elif count > n*2:
            return -1

print(solve())