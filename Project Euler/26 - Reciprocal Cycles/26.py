reciprocal = [0]*1001
remainder_cnt = [0]*1000

for i in range(2, 1000):
    for j in range(1000):
        remainder_cnt[j] = 0
    quotient = 10
    cnt = 0
    while True:
        if quotient%i == 0:
            reciprocal[i] = 0
            break
        elif remainder_cnt[quotient%i] != 0:
            reciprocal[i] = cnt - remainder_cnt[quotient%i] + 1
            break
        cnt = cnt + 1
        remainder_cnt[quotient%i] = cnt
        quotient = (quotient - quotient//i*i)*10

reciprocalMax = 0
for i in range(1000):
    if reciprocalMax < reciprocal[i]:
        reciprocalMax = reciprocal[i]
        idx = i
print(idx)