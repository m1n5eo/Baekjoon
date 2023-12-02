arr = []
for i in range(100):
	n = input()
	arr.append(n)

sum = 0
for i in range(100):
	sum = sum + int(arr[i])

for i in range(10):
	print(str(sum)[i], end="")