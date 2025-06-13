import sys
input = sys.stdin.readline

def fibonacci(n):
    global result

    f = [0, 1, 1] + [0 for _ in range(40)]
    for i in range(3, n+1):
        f[i] = f[i-1] + f[i-2]
    
    return f[n]

n = int(input())
print(fibonacci(n), n-2)