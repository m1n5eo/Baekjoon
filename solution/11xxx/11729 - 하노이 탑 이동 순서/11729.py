import sys
input = sys.stdin.readline

def hanoi(n, start, mid, end):
    if n == 1:
        print(start, end)
        return
    
    hanoi(n-1, start, end, mid)
    hanoi(1, start, mid, end)
    hanoi(n-1, mid, start, end)

n = int(input())

print(2**n - 1)
hanoi(n, 1, 2, 3)