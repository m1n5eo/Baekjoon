str = input()

stack = []

for i in range(len(str)):
    stack.append(str[i])
    
    if len(stack) > 3:
        if stack[len(stack)-4] == 'P' and stack[len(stack)-3] == 'P' and stack[len(stack)-2] == 'A' and stack[len(stack)-1] == 'P':
            stack.pop()
            stack.pop()
            stack.pop()

if len(stack) == 1 and stack[0] == 'P' and str != 'P':
    print("PPAP")
else:
    print("NP")