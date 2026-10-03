import sys
input = sys.stdin.readline

def func(x, y, s):
    for i in range(x, x+s):
        for j in range(y, y+s):
            if table[i][j] != table[x][y]:
                print("(", end="")
                func(x, y, s//2)
                func(x, y+s//2, s//2)
                func(x+s//2, y, s//2)
                func(x+s//2, y+s//2, s//2)
                print(")", end="")
                return

    print(table[x][y], end="")
    return

if __name__ == '__main__':
    n = int(input())
    table = [list(input()[:-1]) for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            table[i][j] = int(table[i][j])
    
    func(0, 0, n)