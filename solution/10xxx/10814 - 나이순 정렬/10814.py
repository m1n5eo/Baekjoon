import sys
input = sys.stdin.readline

n = int(input())
for user in sorted([list(map(str, input().split())) for _ in range(n)], key = lambda x: int(x[0])):
    print(user[0], user[1])