import math
import sys
input = sys.stdin.readline

n = int(input())
speed = list()

for i in range(n):
    x, y, v = map(int, input().split())
    dist = (x**2+y**2)**(1/2)

    speed.append([dist/v, i+1])

speed.sort()

for i in range(n):
    print(speed[i][1])