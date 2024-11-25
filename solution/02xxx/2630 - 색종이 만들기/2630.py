import sys
input = sys.stdin.readline

def func(x, y, s):
    for i in range(x, x+s):
        for j in range(y, y+s):
            if table[i][j] != table[x][y]:
                func(x, y, s//2)
                func(x+s//2, y, s//2)
                func(x, y+s//2, s//2)
                func(x+s//2, y+s//2, s//2)
                return
                
    count[table[x][y]] += 1

if __name__ == '__main__':
    n = int(input())
    table = [list(map(int, input().split())) for _ in range(n)]
    count = [0 for _ in range(2)]

    func(0, 0, n)

    print(count[0], count[1], sep="\n")