import sys
input = sys.stdin.readline

n = input()[:-1]
check = False

for i in range(len(n)):
    if n[i] == '7':
        check = True
        break

n = int(n)

if check == False and n%7 != 0:
    print(0)
elif check == False and n%7 == 0:
    print(1)
elif check == True and n%7 != 0:
    print(2)
elif check == True and n%7 == 0:
    print(3)