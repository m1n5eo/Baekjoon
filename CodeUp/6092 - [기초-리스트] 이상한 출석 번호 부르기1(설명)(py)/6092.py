n = int(input())
k = input().split()
a = []

for i in range(24):
    a.append(0)

for i in range(n):
    k[i] = int(k[i])

for i in range(n):
    a[k[i]] += 1

for i in range(1, 24):
    print(a[i], end=" ")