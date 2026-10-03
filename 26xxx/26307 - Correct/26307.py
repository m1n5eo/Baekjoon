import sys
input = sys.stdin.readline

h, m = map(int, input().split())
time = h*60+m

print(time - 9*60)