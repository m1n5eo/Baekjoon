import sys
import math
input = sys.stdin.readline

MAX = 555555

m = int(input())
f = [0] + list(map(int, input().split()))

sparseTable = [f] + [[0 for _ in range(m+1)] for _ in range(int(math.log2(MAX)))]

for i in range(1, int(math.log2(MAX))):
    for j in range(1, m+1):
        sparseTable[i][j] = sparseTable[i-1][sparseTable[i-1][j]]

q = int(input())

for _ in range(q):
    n, x = map(int, input().split()) # n은 이동 횟수, x는 시작 지점
    result = x
    count = 0

    while n:
        if n%2 == 1:
            result = sparseTable[count][result]

        n //= 2
        count += 1
    
    print(result)