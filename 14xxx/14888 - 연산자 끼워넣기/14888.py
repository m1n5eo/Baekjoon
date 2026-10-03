import sys
input = sys.stdin.readline

MAX = 1234567890

def calculate(idx, now):
    global n, a, arithmetic, result

    if n == idx:
        result = [min(result[0], now), max(result[1], now)]
        return
    
    if arithmetic[0] > 0:
        arithmetic[0] -= 1
        calculate(idx+1, now+a[idx])
        arithmetic[0] += 1
    if arithmetic[1] > 0:
        arithmetic[1] -= 1
        calculate(idx+1, now-a[idx])
        arithmetic[1] += 1
    if arithmetic[2] > 0:
        arithmetic[2] -= 1
        calculate(idx+1, now*a[idx])
        arithmetic[2] += 1
    if arithmetic[3] > 0:
        arithmetic[3] -= 1
        calculate(idx+1, (now if now > 0 else now+(a[idx]-1))//a[idx])
        arithmetic[3] += 1

n = int(input())
a = list(map(int, input().split()))
arithmetic = list(map(int, input().split()))
result = [MAX, -MAX]

calculate(1, a[0])

print(result[1])
print(result[0])