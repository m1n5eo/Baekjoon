import sys
input = sys.stdin.readline

def f(n, m, result):
    if len(result) == m:
        for r in result:
            print(r, end=" ")
        print()
        return

    for i in range(1, n+1):
        f(n, m, result + [i])

n, m = map(int, input().split())
f(n, m, [])