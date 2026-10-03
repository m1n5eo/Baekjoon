import sys
input = sys.stdin.readline

n = int(input()) - 1
x, y = 1, 1

while n:
    if (x + y) % 2 == 0:
        y += 1
        if x != 1:
            x -= 1
    elif (x + y) % 2 == 1:
        x += 1
        if y != 1:
            y -= 1
    n -= 1

print(x, '/', y, sep="")