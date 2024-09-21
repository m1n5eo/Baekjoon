import sys
input = sys.stdin.readline

def isPrime(num):
    i = 2

    while True:
        if num%i == 0:
            return False
        elif i*i >= num:
            break
        i += 1
    
    return True

t = int(input())

for _ in range(t):
    n = int(input())

    if n <= 2:
        print(2)
        continue

    while not isPrime(n):
        n += 1
    
    print(n)