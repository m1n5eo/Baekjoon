import sys
input = sys.stdin.readline

stack = list()

for _ in range(int(input())):
    n = int(input())

    if n != 0:
        stack.append(n)
    elif n == 0:
        stack.pop()

print(sum(stack))