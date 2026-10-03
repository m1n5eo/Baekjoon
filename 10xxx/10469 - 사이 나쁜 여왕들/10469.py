import sys
input = sys.stdin.readline

def solve(chess):
    count = 0
    for i in range(8):
        for j in range(8):
            if chess[i][j] == '*':
                count += 1
                for x in range(-8, 9):
                    if x == 0: continue
                    if 0 <= i+x and i+x < 8 and chess[i+x][j] == '*': return "invalid", count
                    if 0 <= j+x and j+x < 8 and chess[i][j+x] == '*': return "invalid", count
                    if 0 <= i+x and i+x < 8 and 0 <= j+x and j+x < 8 and chess[i+x][j+x] == '*': return "invalid", count
                    if 0 <= i-x and i-x < 8 and 0 <= j+x and j+x < 8 and chess[i-x][j+x] == '*': return "invalid", count
    return "valid", count

result, count = solve([input()[:-1] for _ in range(8)])
print("invalid" if count != 8 or result == "invalid" else "valid")