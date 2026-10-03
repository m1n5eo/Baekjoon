import sys
input = sys.stdin.readline

MAX = 1111111

cnt = [0 for _ in range(2)] + [1 for _ in range(MAX-2)]

for i in range(2, MAX):
    for j in range(i*2, MAX, i):
        cnt[j] += i

tc = 1

while True:
    start, stop, badness = map(int, input().split())

    if start == 0 and stop == 0 and badness == 0:
        break

    count = 0

    for x in range(start, stop+1):
        if abs(cnt[x]-x) <= badness:
            count += 1
    
    print("Test ", tc, ": ", count, sep="")
    tc += 1