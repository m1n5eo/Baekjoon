import sys
input = sys.stdin.readline

while True:
    data = input()[:-1]
    stack = list()
    result = "yes"

    if data == '.':
        break

    for d in data:
        if d == '(':
            stack.append(d)
        elif d == ')':
            if len(stack) == 0 or stack[-1] == '[':
                result = "no"
                break
            elif stack[-1] == '(':
                stack.pop()
        elif d == '[':
            stack.append(d)
        elif d == ']':
            if len(stack) == 0 or stack[-1] == '(':
                result = "no"
                break
            elif stack[-1] == '[':
                stack.pop()
    
    print(result if len(stack) == 0 else "no")