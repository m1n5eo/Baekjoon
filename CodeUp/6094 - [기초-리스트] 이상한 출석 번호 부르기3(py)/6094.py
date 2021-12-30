n = int(input())
k = input().split()
min = 1234567890
for i in range(n):
    k[i] = int(k[i])
    if(k[i] < min):
        min = k[i]
print(min)