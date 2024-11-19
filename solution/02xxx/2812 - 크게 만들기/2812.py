import sys
input = sys.stdin.readline

if __name__ == '__main__':
    n, k = map(int, input().split())
    number = list(map(int, input()[:-1]))
    stack = list()
    m = n-k
    
    for i in range(n):
        while stack and stack[-1] < number[i] and k > 0:
            stack.pop()
            k -= 1
        
        stack.append(number[i])
        
    for s in stack[:m]:
        print(s, end="")