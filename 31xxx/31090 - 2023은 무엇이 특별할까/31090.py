import sys
input = sys.stdin.readline

t = int(input())

for testcase in range(t):
    n = int(input())
    print("Good" if (n+1)%(n%100) == 0 else "Bye")