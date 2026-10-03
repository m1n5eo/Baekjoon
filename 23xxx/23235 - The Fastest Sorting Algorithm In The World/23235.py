import sys
input = sys.stdin.readline

cnt = 0

while True:
    l = list(map(int, input().split()))
    cnt += 1

    if l[0] == 0:
        break

    print("Case ", cnt, ": Sorting... done!", sep="")