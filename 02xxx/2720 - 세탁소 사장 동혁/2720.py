import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    money = int(input())

    print(money // 25, end=" ")
    money -= money // 25 * 25
    print(money // 10, end=" ")
    money -= money // 10 * 10
    print(money // 5, end=" ")
    money -= money // 5 * 5
    print(money)