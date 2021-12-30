n = int(input())

if n==12:
    n = 0
    
if n//3==0:
    print('winter')
elif n//3==1:
    print('spring')
elif n//3==2:
    print('summer')
else:
    print('fall')