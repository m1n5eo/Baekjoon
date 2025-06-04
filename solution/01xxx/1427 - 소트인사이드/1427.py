import sys
input = sys.stdin.readline

n = int(input())
save = list()

while n:
    save.append(n%10)
    n //= 10

for s in sorted(save, reverse=True):
    print(s, end="")