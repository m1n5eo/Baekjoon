import sys
input = sys.stdin.readline

t = int(input())

for testcase in range(1, t+1):
    l = list(map(int, input().split()))

    num = l[0]
    l.pop(0)
    l.sort()

    gap = 0

    for i in range(0, num-1):
        if l[i+1]-l[i] > gap:
            gap = l[i+1]-l[i]

    print("Class ", testcase, sep="")
    print("Max ", l[num-1], ", Min ", l[0], ", Largest gap ", gap, sep="")