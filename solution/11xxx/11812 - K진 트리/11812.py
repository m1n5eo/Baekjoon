import sys
input = sys.stdin.readline

def parent(x):
    return (x-2)//k+1

def find(x, y):
    return max(x, y)

n, k, m = map(int, input().split())

for _ in range(m):
    a, b = map(int, input().split())
    count = 0

    if k == 1:
        print(abs(a-b))
        continue

    while a != b:
        count += 1

        if a > b:
            a = parent(a)
        else:
            b = parent(b)
    
    print(count)