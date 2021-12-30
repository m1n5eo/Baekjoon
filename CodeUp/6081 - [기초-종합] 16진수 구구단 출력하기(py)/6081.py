ch = input()
if ch == 'A':
    n = 10
elif ch == 'B':
    n = 11
elif ch == 'C':
    n = 12
elif ch == 'D':
    n = 13
elif ch == 'E':
    n = 14
else:
    n = 15
for i in range(1, 16):
    print('%X*%X=%X'%(n, i, n*i))