import sys
input = sys.stdin.readline

for _ in range(int(input())):
    data = input()[:-1]
    stack = list()
    result = "YES"

    for d in data:
        if d == '(':
            stack.append('(')
        else:
            if len(stack) == 0:
                result = "NO"
                break
            else:
                stack.pop()
    
    print(result if len(stack) == 0 else "NO")