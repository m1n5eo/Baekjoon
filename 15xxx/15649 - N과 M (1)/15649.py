import sys
input = sys.stdin.readline

def f(n, m, result, check):
    if len(result) == m:
        for r in result:
            print(r, end=" ")
        print()
        return

    for i in range(1, n+1):
        if check[i] == False:
            check[i] = True
            f(n, m, result + [i], check)
            check[i] = False

n, m = map(int, input().split())
f(n, m, [], [False for _ in range(n+1)])