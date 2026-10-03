import sys
input = sys.stdin.readline

integer = sorted([int(input()) for _ in range(5)])
print(int(sum(integer)/len(integer)), integer[2], sep='\n')