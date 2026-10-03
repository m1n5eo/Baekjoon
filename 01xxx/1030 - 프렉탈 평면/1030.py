import sys
input = sys.stdin.readline

def fractal(x, y, num):
    if (n-k)//2 <= x//num%n and x//num%n < n-(n-k)//2 and (n-k)//2 <= y//num%n and y//num%n < n-(n-k)//2:
        return 1
    elif num//n == 0:
        return 0
    else:
        return fractal(x, y, num//n)

if __name__ == '__main__':
    s, n, k, r1, r2, c1, c2 = map(int, input().split())
    
    for x in range(r1, r2+1):
        for y in range(c1, c2+1):
            print(fractal(x, y, n**s), end="")
        print()