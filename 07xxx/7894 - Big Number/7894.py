import math
import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    ret = 0
    for i in range(1, n+1):
        ret += math.log(i, 10)
    return int(ret) + 1

if __name__ == '__main__':
    tc = int(input())
    sol = list()
    while tc:
        sol.append(solve())
        tc -= 1
    for s in sol: print(s)