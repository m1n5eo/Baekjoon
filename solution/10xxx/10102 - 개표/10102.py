n = int(input())
str = input()

cntA = 0
cntB = 0

for i in range(n):
    if str[i] == 'A':
        cntA += 1
    elif str[i] == 'B':
        cntB += 1

if cntA > cntB:
    print('A')
elif cntA < cntB:
    print('B')
else:
    print("Tie")