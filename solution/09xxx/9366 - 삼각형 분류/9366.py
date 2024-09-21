import sys
input = sys.stdin.readline

n = int(input())

for i in range(1, n+1):
    l = list(map(int, input().split()))
    l.sort()

    if l[0]+l[1] <= l[2]:
        print("Case #", i, ": invalid!", sep="")
    elif l[0] == l[2]:
        print("Case #", i, ": equilateral", sep="")
    elif l[0] == l[1] or l[1] == l[2]:
        print("Case #", i, ": isosceles", sep="")
    else:
        print("Case #", i, ": scalene", sep="")