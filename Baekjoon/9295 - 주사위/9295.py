n = int(input())

for i in range(n):
    s = input().split()

    print("Case ", end="")
    print(i+1, end="")
    print(": ", end="")
    print(int(s[0])+int(s[1]))