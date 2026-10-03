import sys
input = sys.stdin.readline

def w(a, b, c):
    global save

    if save[a][b][c]:
        return save[a][b][c]

    if a <= 0 or b <= 0 or c <= 0: save[a][b][c] = 1
    elif a < b and b < c: save[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    else: save[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
    
    return save[a][b][c]

save = [[[0 for _ in range(44)] for _ in range(44)] for _ in range(44)]

while True:
    a, b, c = map(int, input().split())
    result = "w(" + str(a) + ", " + str(b) + ", " + str(c) + ") = "

    if a == -1 and b == -1 and c == -1:
        break

    if a <= 0 or b <= 0 or c <= 0: a, b, c = map(int, "0 0 0".split())
    elif a > 20 or b > 20 or c > 20: a, b, c = map(int, "20 20 20".split())

    print(result + str(w(a, b, c)))