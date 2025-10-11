import sys
input = sys.stdin.readline

def solve(num):
    k = 1
    ret = 0
    while num >= k:
        ret += k*((num-k)//(k*2)+1)
        k *= 2
    return ret

if __name__ == '__main__':
    n, m = map(int, input().split())
    print(solve(m) - solve(n-1))