import sys
input = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    dummy = list(map(int, input().split()))

    grundy = 0
    for d in dummy:
        grundy ^= d
    
    print("koosaga" if grundy != 0 else "cubelover")