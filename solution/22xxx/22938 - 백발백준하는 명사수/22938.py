import sys
input = sys.stdin.readline

Ax, Ay, Ar = map(int, input().split())
Bx, By, Br = map(int, input().split())

dist = ((Ax-Bx)**2+(Ay-By)**2)**(1/2)

if dist < Ar+Br:
    print("YES")
else:
    print("NO")