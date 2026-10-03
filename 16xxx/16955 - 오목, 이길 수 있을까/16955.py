import sys
input = sys.stdin.readline

def solve(baduk):
    for i in range(10):
        for j in range(10):
            if baduk[i][j] == '.':
                if (0 <= i+1 and i+4 < 10) and baduk[i+1][j] == 'X' and baduk[i+2][j] == 'X' and baduk[i+3][j] == 'X' and baduk[i+4][j] == 'X': return 1
                elif (0 <= i-1 and i+3 < 10) and baduk[i-1][j] == 'X' and baduk[i+1][j] == 'X' and baduk[i+2][j] == 'X' and baduk[i+3][j] == 'X': return 1
                elif (0 <= i-2 and i+2 < 10) and baduk[i-2][j] == 'X' and baduk[i-1][j] == 'X' and baduk[i+1][j] == 'X' and baduk[i+2][j] == 'X': return 1
                elif (0 <= i-3 and i+1 < 10) and baduk[i-3][j] == 'X' and baduk[i-2][j] == 'X' and baduk[i-1][j] == 'X' and baduk[i+1][j] == 'X': return 1
                elif (0 <= i-4 and i-1 < 10) and baduk[i-4][j] == 'X' and baduk[i-3][j] == 'X' and baduk[i-2][j] == 'X' and baduk[i-1][j] == 'X': return 1
                elif (0 <= j+1 and j+4 < 10) and baduk[i][j+1] == 'X' and baduk[i][j+2] == 'X' and baduk[i][j+3] == 'X' and baduk[i][j+4] == 'X': return 1
                elif (0 <= j-1 and j+3 < 10) and baduk[i][j-1] == 'X' and baduk[i][j+1] == 'X' and baduk[i][j+2] == 'X' and baduk[i][j+3] == 'X': return 1
                elif (0 <= j-2 and j+2 < 10) and baduk[i][j-2] == 'X' and baduk[i][j-1] == 'X' and baduk[i][j+1] == 'X' and baduk[i][j+2] == 'X': return 1
                elif (0 <= j-3 and j+1 < 10) and baduk[i][j-3] == 'X' and baduk[i][j-2] == 'X' and baduk[i][j-1] == 'X' and baduk[i][j+1] == 'X': return 1
                elif (0 <= j-4 and j-1 < 10) and baduk[i][j-4] == 'X' and baduk[i][j-3] == 'X' and baduk[i][j-2] == 'X' and baduk[i][j-1] == 'X': return 1
                elif (0 <= i+1 and i+4 < 10) and (0 <= j+1 and j+4 < 10) and baduk[i+1][j+1] == 'X' and baduk[i+2][j+2] == 'X' and baduk[i+3][j+3] == 'X' and baduk[i+4][j+4] == 'X': return 1
                elif (0 <= i-1 and i+3 < 10) and (0 <= j-1 and j+3 < 10) and baduk[i-1][j-1] == 'X' and baduk[i+1][j+1] == 'X' and baduk[i+2][j+2] == 'X' and baduk[i+3][j+3] == 'X': return 1
                elif (0 <= i-2 and i+2 < 10) and (0 <= j-2 and j+2 < 10) and baduk[i-2][j-2] == 'X' and baduk[i-1][j-1] == 'X' and baduk[i+1][j+1] == 'X' and baduk[i+2][j+2] == 'X': return 1
                elif (0 <= i-3 and i+1 < 10) and (0 <= j-3 and j+1 < 10) and baduk[i-3][j-3] == 'X' and baduk[i-2][j-2] == 'X' and baduk[i-1][j-1] == 'X' and baduk[i+1][j+1] == 'X': return 1
                elif (0 <= i-4 and i-1 < 10) and (0 <= j-4 and j-1 < 10) and baduk[i-4][j-4] == 'X' and baduk[i-3][j-3] == 'X' and baduk[i-2][j-2] == 'X' and baduk[i-1][j-1] == 'X': return 1
                elif (0 <= i+1 and i+4 < 10) and (0 <= j-4 and j-1 < 10) and baduk[i+1][j-1] == 'X' and baduk[i+2][j-2] == 'X' and baduk[i+3][j-3] == 'X' and baduk[i+4][j-4] == 'X': return 1
                elif (0 <= i-1 and i+3 < 10) and (0 <= j-3 and j+1 < 10) and baduk[i-1][j+1] == 'X' and baduk[i+1][j-1] == 'X' and baduk[i+2][j-2] == 'X' and baduk[i+3][j-3] == 'X': return 1
                elif (0 <= i-2 and i+2 < 10) and (0 <= j-2 and j+2 < 10) and baduk[i-2][j+2] == 'X' and baduk[i-1][j+1] == 'X' and baduk[i+1][j-1] == 'X' and baduk[i+2][j-2] == 'X': return 1
                elif (0 <= i-3 and i+1 < 10) and (0 <= j-1 and j+3 < 10) and baduk[i-3][j+3] == 'X' and baduk[i-2][j+2] == 'X' and baduk[i-1][j+1] == 'X' and baduk[i+1][j-1] == 'X': return 1
                elif (0 <= i-4 and i-1 < 10) and (0 <= j+1 and j+4 < 10) and baduk[i-4][j+4] == 'X' and baduk[i-3][j+3] == 'X' and baduk[i-2][j+2] == 'X' and baduk[i-1][j+1] == 'X': return 1
    return 0

print(solve([input()[:-1] for _ in range(10)]))