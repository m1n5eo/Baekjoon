import sys
input = sys.stdin.readline

setting = [[0 for j in range(5)] for i in range(11)]

for i in range(1, 5):
    setting[0][i] = 10

for i in range(1, 10):
    setting[i][1] = i

for i in range(1, 10):
    for j in range(2, 5):
        setting[i][j] = (setting[i][j-1]*i)%10

for i in range(10):
    setting[i][0] = setting[i][4]

t = int(input())

for testcase in range(t):
    a, b = map(int, input().split())
    print(setting[a%10][b%4])