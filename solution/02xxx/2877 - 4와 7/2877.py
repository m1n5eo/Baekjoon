import sys
input = sys.stdin.readline

for b in bin(int(input()) + 1)[3:]:
    print(4 if b == '0' else 7, end="")