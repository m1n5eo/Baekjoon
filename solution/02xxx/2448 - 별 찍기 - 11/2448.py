import sys
import math
input = sys.stdin.readline

MAX = 3333

standard = [[" ", " ", "*", " ", " ", " "],
            [" ", "*", " ", "*", " ", " "],
            ["*", "*", "*", "*", "*", " "]]

def star(x, y, size):
    if size == 0:
        for i in range(3):
            for j in range(6):
                result[x+i][y+j-2] = standard[i][j]
        return
    
    star(x, y, size-1)
    star(x + 3*2**(size-1), y - 3*2**(size-1), size-1)
    star(x + 3*2**(size-1), y + 3*2**(size-1), size-1)

n = int(input())
result = [[" " for _ in range(n*2)] for _ in range(n)]

star(0, n-1, int(math.log2(n//3)))

for i in range(n):
    for j in range(n*2):
        print(result[i][j], end="")
    print()