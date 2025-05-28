import sys
input = sys.stdin.readline

n, m = map(str, input().split())

n = int(n[2] + n[1] + n[0])
m = int(m[2] + m[1] + m[0])

print(n if n > m else m)