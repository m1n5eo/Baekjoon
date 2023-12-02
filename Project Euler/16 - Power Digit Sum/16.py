two = 1
for i in range(1000):
	two = two*2

sum = 0
two_str = str(two)
for i in range(len(two_str)):
	sum = sum + int(two_str[i])
print(sum)