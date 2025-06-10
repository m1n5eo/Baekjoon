import sys
input = sys.stdin.readline

def f(n, m, result, s):
    if len(result) == m:
        for r in result:
            print(r, end=" ")
        print()
        return

    for i in range(s, n+1):
        f(n, m, result + [i], i)

n, m = map(int, input().split())
f(n, m, [], 1)