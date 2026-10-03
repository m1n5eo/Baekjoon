import sys
input = sys.stdin.readline

t = int(input())

for testcase in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())

    if x1 == x2 and y1 == y2:
        if r1 == r2:
            print(-1)
        elif r1 != r2:
            print(0)
        continue
    
    d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)

    if max(r1, r2)*max(r1, r2) <= d:
        if (r1+r2)*(r1+r2) > d:
            print(2)
        elif (r1+r2)*(r1+r2) == d:
            print(1)
        else:
            print(0)
    else:
        if (r1-r2)*(r1-r2) == d:
            print(1)
        elif (r1-r2)*(r1-r2) < d:
            print(2)
        else:
            print(0)