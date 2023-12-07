prime = [False]*2 + [True]*3333331
maxQuadratic = 0

for i in range(2, 3333333):
    if prime[i] == True:
        for j in range(i*2, 3333333, i):
            prime[j] = False

for a in range(-999, 1000):
    for b in range(-1000, 1001):
        idx = 0
        while True:
            temp = idx*idx + idx*a + b
            if temp > 0 and prime[temp] == True:
                idx = idx + 1
            else:
                break
        if maxQuadratic < idx:
            maxQuadratic = idx
            aa = a
            bb = b

print(aa*bb)