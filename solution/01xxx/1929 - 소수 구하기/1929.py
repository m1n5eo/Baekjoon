import sys
input = sys.stdin.readline

prime = [False, False] + [True for _ in range(1111111-2)]

for i in range(2, 1111111):
    if prime[i] == True:
        for j in range(i*2, 1111111, i):
            prime[j] = False

n, m = map(int, input().split())

for i in range(n, m+1):
    if prime[i] == True:
        print(i)