import sys
input = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    dummy = list(map(int, input().split()))

    g = 0
    for d in dummy:
        g ^= d

    count = 0
    for i in range(len(dummy)):
        grundy = 0
        for j in range(len(dummy)):
            if i == j:
                continue
            grundy ^= dummy[j]

        for num in range(dummy[i]):
            if grundy ^ num == 0:
                count += 1
    
    if g != 0:
        print(count if len(dummy) != 1 else 1)
    else:
        print(0)