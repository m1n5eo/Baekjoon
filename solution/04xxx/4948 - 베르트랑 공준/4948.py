import sys
input = sys.stdin.readline

prime = [False, False] + [True for _ in range(333333-2)]

for i in range(2, 333333):
    if prime[i] == True:
        for j in range(i*2, 333333, i):
            prime[j] = False

while True:
    n = int(input())
    count = 0

    if n == 0:
        break

    for i in range(n+1, 2*n+1):
        if prime[i] == True:
            count += 1
        
    print(count)