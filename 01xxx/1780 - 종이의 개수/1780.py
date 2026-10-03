import sys
input = sys.stdin.readline

def func(x, y, s):
    for i in range(x, x+s):
        for j in range(y, y+s):
            if table[i][j] != table[x][y]:
                size = s//3
                for ii in range(3):
                    for jj in range(3):
                        func(x+size*ii, y+size*jj, size)
                return
    count[table[x][y]] += 1

if __name__ == '__main__':
    n = int(input())
    table = [list(map(int, input().split())) for _ in range(n)]
    count = [0 for _ in range(3)]

    func(0, 0, n)

    print(count[-1])
    print(count[0])
    print(count[1])