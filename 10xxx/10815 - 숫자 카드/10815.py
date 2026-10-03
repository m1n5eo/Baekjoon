import sys
input = sys.stdin.readline

n = int(input())
a = set(map(int, input().split()))
m = int(input())
card = list(map(int, input().split()))

for c in card:
    print(1 if c in a else 0, end=" ")