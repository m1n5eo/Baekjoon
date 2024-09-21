str1 = input()
str2 = list(input())

n = len(str2)

res = []

for c in str1:
    res.append(c)
    if res[-n:] == str2:
        for _ in range(n):
            res.pop()

if res:
    print(''.join(res))
else:
    print("FRULA")