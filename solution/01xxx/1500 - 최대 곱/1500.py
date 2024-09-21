import sys
input = sys.stdin.readline

s, k = map(int, input().split())
print(((s//k)**(k-s%k))*((s//k+1)**(s%k)))