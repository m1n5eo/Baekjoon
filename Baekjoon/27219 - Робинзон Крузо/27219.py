import sys
input = sys.stdin.readline

n = int(input())
result = "V"*(n//5) + "I"*(n%5)

print(result)