import sys
input = sys.stdin.readline

now = int(input())
alarm = int(input())

if 20 <= now:
    print(alarm+24 - now)
else:
    print(alarm - now)