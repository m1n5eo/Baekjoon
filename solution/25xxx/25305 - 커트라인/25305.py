import sys
input = sys.stdin.readline

n, k = map(int, input().split())
print(sorted(list(map(int, input().split())), reverse=True)[k-1])