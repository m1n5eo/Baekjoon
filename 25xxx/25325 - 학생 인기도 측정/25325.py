import sys
input = sys.stdin.readline

n = int(input())
name = dict()

for l in list(map(str, input().split())):
    name[l] = 0

for _ in range(n):
    for l in list(map(str, input().split())):
        name[l] += 1

for n in sorted(name.items(), key=lambda x: (-x[1], x[0])):
    print(n[0], n[1])