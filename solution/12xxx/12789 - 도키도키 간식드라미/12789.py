import sys
input = sys.stdin.readline

n = int(input())
ticket = list(map(int, input().split()))
stack = list()

result = "Nice"
now = 1

while len(ticket) + len(stack):
    if len(stack) != 0 and stack[-1] == now:
        stack.pop()
        now += 1
    elif len(ticket) != 0 and ticket[0] == now:
        ticket.pop(0)
        now += 1
    elif len(ticket) != 0 and ticket[0] != now:
        stack.append(ticket[0])
        ticket.pop(0)
    else:
        result = "Sad"
        break

print(result)