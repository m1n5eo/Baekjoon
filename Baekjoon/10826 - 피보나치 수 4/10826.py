first = 0
second = 1

n = int(input())
for i in range(n):
    temp = first+second
    first = second
    second = temp

print(first)