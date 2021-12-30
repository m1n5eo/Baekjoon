n = int(input())
m = int(input())
k = int(input())
g = str(n*m*k)
for i in range(0,10):
    print(g.count(str(i)))