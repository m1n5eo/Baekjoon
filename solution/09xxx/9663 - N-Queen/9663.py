import sys
input = sys.stdin.readline

array = [0 for _ in range(16)]
result = 0

def check(k):
    for i in range(0, k):
        if array[k] == array[i] or abs(array[k]-array[i]) == abs(k-i):
            return False
    return True

def func(cnt):
    global result

    if cnt == n:
        result += 1
        return
    
    for i in range(n):
        array[cnt] = i

        if check(cnt) == True:
            func(cnt+1)

n = int(input())
func(0)
print(result)