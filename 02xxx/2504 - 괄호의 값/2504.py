sum = 0
idx = -1
temp = 1
stack = []

str = input()
strlen = len(str)

for i in range(strlen):
    if str[i] == '(' or str[i] == '[':
        stack.append(str[i])
    elif str[i] == ')' and len(stack) != 0 and stack[-1] == '(':
        stack.pop()
    elif str[i] == ']' and len(stack) != 0 and stack[-1] == '[':
        stack.pop()
    else:
        print(sum)
        exit()

if len(stack) != 0:
    print("0")
    exit()

i = 0
while i < strlen:
    if str[i] == '(':
        temp = temp*2
        stack.append('(')
        if i+1 < strlen and str[i+1] == ')':
            sum = sum+temp
            temp = temp/2
            stack.pop()
            i = i+1
    elif str[i] == '[':
        temp = temp*3
        stack.append('[')
        if i+1 < strlen and str[i+1] == ']':
            sum = sum+temp
            temp = temp/3
            stack.pop()
            i = i+1
    elif str[i] == ')':
        stack.pop()
        temp = temp/2
    elif str[i] == ']':
        stack.pop()
        temp = temp/3
    i = i+1

print(int(sum))