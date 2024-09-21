import sys
input = sys.stdin.readline

zero = [1, 0]
one = [0, 1]

for i in range(2, 41):
    zero.append(zero[i-1] + zero[i-2])
    one.append(one[i-1] + one[i-2])

t = int(input())

for _ in range(t):
    n = int(input())
    print(zero[n], one[n], sep=" ", end="\n")