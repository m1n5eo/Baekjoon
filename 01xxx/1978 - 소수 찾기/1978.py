import sys
input = sys.stdin.readline

prime = [False, False] + [True for _ in range(1111)]

for i in range(1111):
    if prime[i] == True:
        for j in range(i*2, 1111, i):
            prime[j] = False

n = int(input())
integer = list(map(int, input().split()))
count = 0

for i in integer:
    if prime[i] == True:
        count += 1

print(count)