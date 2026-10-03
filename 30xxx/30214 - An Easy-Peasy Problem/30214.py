import sys
input = sys.stdin.readline

n, m = map(int, input().split())

if n*2 >= m:
    print("E")
else:
    print("H")