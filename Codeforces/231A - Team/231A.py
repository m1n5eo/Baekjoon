n = int(input())
cnt = 0
for i in range(n):
    petya, vasya, tonya = map(int, input().split())
    if petya and vasya:
        cnt += 1
    elif vasya and tonya:
        cnt += 1
    elif petya and tonya:
        cnt += 1
print(cnt)