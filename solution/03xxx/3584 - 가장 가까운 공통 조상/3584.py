import sys
input = sys.stdin.readline

testcase = int(input())

for _ in range(testcase):
    n = int(input())
    parent = list()
    visit = list()

    for i in range(0, n+1):
        parent.append(0)
        visit.append(False)

    for _ in range(n-1):
        a, b = map(int, input().split())
        parent[b] = a

    a, b = map(int, input().split())

    while True:
        if a == 0:
            break
        else:
            visit[a] = True
            a = parent[a]

    while True:
        if visit[b] == True:
            break
        else:
            b = parent[b]

    print(b)