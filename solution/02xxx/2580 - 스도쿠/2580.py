import sys
input = sys.stdin.readline

def check(sudoku, x, y):
    print()

def fill(cnt):
    global sudoku
    global check

    if cnt == 81:
        for su in sudoku:
            for s in su:
                print(s, end=" ")
            print()
        sys.exit()

    x, y = cnt//9, cnt%9

    if sudoku[x][y] != 0:
        fill(cnt+1)
    elif sudoku[x][y] == 0:
        for k in range(1, 10):
            if (not check[0][x][k]) and (not check[1][y][k]) and (not check[2][x//3*3 + y//3][k]):
                sudoku[x][y] = k
                check[0][x][k] = True
                check[1][y][k] = True
                check[2][x//3*3 + y//3][k] = True

                fill(cnt+1)

                sudoku[x][y] = 0
                check[0][x][k] = False
                check[1][y][k] = False
                check[2][x//3*3 + y//3][k] = False

sudoku = [list(map(int, input().split())) for _ in range(9)]
check = [[[False for _ in range(10)] for _ in range(22)] for _ in range(3)]

for i in range(9):
    for j in range(9):
        k = sudoku[i][j]
        check[0][i][k] = True
        check[1][j][k] = True
        check[2][i//3*3 + j//3][k] = True

fill(0)