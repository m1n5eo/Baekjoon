n = int(input())
print(n * (n//2) if n % 2 else (n//2) * (n-1), 2, sep='\n')