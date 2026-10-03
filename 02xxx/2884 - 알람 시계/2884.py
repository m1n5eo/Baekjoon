h, m = map(int, input().split())
sum = h*60 + m
if sum<45:
    sum = 1440-45+sum
else:
    sum = sum-45

print(int(sum/60), sum%60)