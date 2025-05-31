import sys
input = sys.stdin.readline

prime = [False, False] + [True for _ in range(11111-2)]

for i in range(2, 11111):
    if prime[i] == True:
        for j in range(i*2, 11111, i):
            prime[j] = False

n = int(input())
m = int(input())

sum = 0
minimum = -1

for i in range(n, m+1):
    if prime[i] == True:
        sum += i
        minimum = (i if minimum == -1 else minimum)

print(sum, minimum, sep="\n") if minimum != -1 else print(minimum)