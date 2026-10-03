import math
import sys
input = sys.stdin.readline

prime = [False, False] + [True for _ in range(11111111-2)]

for i in range(2, int(math.sqrt(11111111))):
    if prime[i] == True:
        for j in range(i*2, 11111111, i):
            prime[j] = False

n = int(input())
now = 2

for i in range(11111111):
    if prime[i] == True:
        while n % i == 0:
            n = n // i
            print(i)
    if n == 1:
        break