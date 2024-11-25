import sys
input = sys.stdin.readline

if __name__ == '__main__':
    n, m = map(int, input().split())
    table = [sum(list(map(int, input().split()))) for _ in range(n)]

    grundy = 0
    for t in table:
        grundy ^= t
    
    print("august14" if grundy != 0 else "ainta")