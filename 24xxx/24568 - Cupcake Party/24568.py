import sys
input = sys.stdin.readline

r = int(input())
s = int(input())

cupcake = r*8 + s*3

print(cupcake-28 if cupcake >= 28 else cupcake)