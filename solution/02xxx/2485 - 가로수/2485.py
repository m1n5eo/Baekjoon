import sys
input = sys.stdin.readline

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

tree = [int(input()) for _ in range(int(input()))]
dist = set()

for i in range(1, len(tree)):
    dist.add(tree[i] - tree[i-1])

dist = list(dist)
k = dist[0]

for i in range(1, len(dist)):
    k = gcd(k, dist[i])

print(int((max(tree) - min(tree)) / k + 1 - len(tree)))