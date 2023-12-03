ftr = 1
for i in range(1, 100+1):
	ftr = ftr * i

sum = 0
str_ftr = str(ftr)
for i in range(len(str_ftr)):
	sum = sum + int(str_ftr[i])
print(sum)