a, b, c = map(int, input().split())
k = c
while k%a != 0 or k%b != 0 or k%c != 0:
    k+=1
print(k)