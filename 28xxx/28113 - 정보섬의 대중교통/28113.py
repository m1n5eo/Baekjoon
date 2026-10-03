import sys

input = sys.stdin.readline

n, a, b = map(int, input().split())

bus = a
subway = b if n<b else n

if bus > subway:
    print("Subway")
elif bus < subway:
    print("Bus")
else:
    print("Anything")