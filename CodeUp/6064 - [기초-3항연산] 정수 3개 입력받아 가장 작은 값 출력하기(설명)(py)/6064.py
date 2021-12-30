a, b, c = map(int, input().split())
b = a if a<b else b
print(b if b<c else c)