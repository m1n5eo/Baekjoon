import sys

stack = []

n = int(sys.stdin.readline())

for i in range(n):
	ord = sys.stdin.readline().split()
	if ord[0] == '1':
		stack.append(ord[1])
	elif ord[0] == '2':
		print(-1 if len(stack) == 0 else stack.pop())
	elif ord[0] == '3':
		print(len(stack))
	elif ord[0] == '4':
		print(1 if len(stack) == 0 else 0)
	elif ord[0] == '5':
		print(-1 if len(stack) == 0 else stack[-1])