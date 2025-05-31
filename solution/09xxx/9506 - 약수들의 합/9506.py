import sys
input = sys.stdin.readline

while True:
    n = int(input())
    result = list()

    if n == -1:
        break

    for i in range(1, n//2 + 1):
        if n % i == 0:
            result.append(i)
    
    if sum(result) == n:
        print(n, '=', end=" ")
        for i in range(len(result)):
            print(result[i], end=(' + ' if i != len(result) - 1 else '\n'))
    else:
        print(n, 'is NOT perfect.')