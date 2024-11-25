import sys
input = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    dummy = list(map(int, input().split()))
    
    grundy = 0
    for d in dummy:
        grundy ^= d
    
    if n == 1:
        print("koosaga" if dummy[0] != 1 else "cubelover")
    elif sum(dummy) == n:
        print("koosaga" if n%2 == 0 else "cubelover")
    else:
        print("koosaga" if grundy != 0 else "cubelover")