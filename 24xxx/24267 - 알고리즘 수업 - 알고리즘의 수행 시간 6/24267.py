n = int(input()) - 1
print(sum(i * (n-i) for i in range(1, n+1)), 3, sep='\n')