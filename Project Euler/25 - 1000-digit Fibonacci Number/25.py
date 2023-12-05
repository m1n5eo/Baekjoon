fibo1 = 1
fibo2 = 1
idx = 2

while True:
	if len(str(fibo2)) >= 1000:
		break
	temp = fibo1+fibo2
	fibo1 = fibo2
	fibo2 = temp
	idx = idx+1

print(idx)