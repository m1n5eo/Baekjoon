import sys
input = sys.stdin.readline

n = int(input())
check = False

for _ in range(n):
    str = input()[:-1]

    if str == "Never gonna give you up":
        continue
    elif str == "Never gonna let you down":
        continue
    elif str == "Never gonna run around and desert you":
        continue
    elif str == "Never gonna make you cry":
        continue
    elif str == "Never gonna say goodbye":
        continue
    elif str == "Never gonna tell a lie and hurt you":
        continue
    elif str == "Never gonna stop":
        continue
    else:
        check = True

if check == True:
    print("Yes")
elif check == False:
    print("No")