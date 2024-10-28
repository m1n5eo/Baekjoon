import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    queue = list()
    check = set()

    print(n//m, '.', sep="", end="")
    n = (n%m)*10

    while True:
        if n in check:
            for q in queue:
                if q == n:
                    print('(', end="")
                print(q//m, end="")
            print(')')
            break

        queue.append(n)
        check.add(n)

        n = (n%m)*10