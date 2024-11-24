import sys
input = sys.stdin.readline

def NimGame():
    grundy = 0
    for d in dummy:
        grundy ^= d
    
    return "koosaga" if grundy != 0 else "cubelover"

if __name__ == '__main__':
    n = int(input())
    dummy = list(map(int, input().split()))

    print(NimGame())