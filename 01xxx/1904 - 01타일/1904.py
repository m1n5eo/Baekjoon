import sys
input = sys.stdin.readline

a, b, fibo = 0, 1, 1
for i in range(int(input())-1):
    a = b
    b = fibo
    fibo = (a+b) % 15746

print(fibo)