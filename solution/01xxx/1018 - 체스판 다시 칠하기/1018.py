import sys
input = sys.stdin.readline

def f(x, y):
    count = 0

    for i in range(x, x+8):
        for j in range(y, y+8):
            if (i+j) % 2 == 0 and chess[i][j] == 'W':
                count += 1
            elif (i+j) % 2 == 1 and chess[i][j] == 'B':
                count += 1
    
    return min(count, 64 - count)

n, m = map(int, input().split())
chess = [input()[:-1] for _ in range(n)]
result = 111

for i in range(n-7):
    for j in range(m-7):
        result = min(result, f(i, j))

print(result)