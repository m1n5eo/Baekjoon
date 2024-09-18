import sys
input = sys.stdin.readline

t = int(input())

for testcase in range(t):
    n, m = map(int, input().split())

    k = m-n

    for i in range(1, 100001):
        if i*i >= k:
            if i*i-i < k:
                print(i*2-1)
                break
            else:
                print(i*2-2)
                break