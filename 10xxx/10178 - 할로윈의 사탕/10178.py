n = int(input())

for _ in range(n):
    s = input().split()

    print("You get ", end="")
    print(int(s[0])//int(s[1]), end="")
    print(" piece(s) and your dad gets ", end="")
    print(int(s[0])%int(s[1]), end="")
    print(" piece(s).")