import sys
input = sys.stdin.readline

MAX = 11111111
check = [True]*2 + [False]*MAX
prime = []

for i in range(2, MAX):
    if check[i] == False:
        prime.append(i)
        for j in range(i*2, MAX, i):
            check[j] = True

a, b = map(int, input().split())
result = 0

for i in prime:
    j = i*i
    while(j <= b):
        if(a <= j):
            result += 1
        j *= i

print(result)