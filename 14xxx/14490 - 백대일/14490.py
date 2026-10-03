import math
import sys
input = sys.stdin.readline

MAX = 111111111

n, m = map(int, input().split(':'))
prime = list()
check = [False, False] + [True for _ in range(2, int(math.sqrt(max(n, m)+1)))]

for i in range(2, int(math.sqrt(max(n, m)+1))):
    if check[i] == True:
        prime.append(i)
        for j in range(i*2, int(math.sqrt(max(n, m)+1)), i):
            check[j] = False
    
for p in prime:
    while n%p == 0 and m%p == 0:
        n /= p
        m /= p

print(int(n), ':', int(m), sep="")