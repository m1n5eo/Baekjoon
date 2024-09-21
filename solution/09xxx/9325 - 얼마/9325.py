t = int(input())

for _ in range(t):
    price = int(input())
    n = int(input())

    for _ in range(n):
        a = input().split()
        price += int(a[0])*int(a[1])
    
    print(price)