import sys
input = sys.stdin.readline

MAX = 1111111
prime = []
check = [True]*2 + [False]*MAX

for i in range(2, MAX):
    if check[i] == False:
        prime.append(i)
        for j in range(i*2, MAX, i):
            check[j] = True

t = int(input())

for _ in range(t):
    n = int(input())
    i = 0
    cnt = 0

    while n//2 >= prime[i]:
        if check[n-prime[i]] == False:
            cnt += 1
        i += 1
    
    print(cnt)