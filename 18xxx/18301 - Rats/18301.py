import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
result = (n+1)*(m+1)//(k+1)-1

print(result)