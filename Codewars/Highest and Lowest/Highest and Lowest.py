def high_and_low(numbers):
    num = numbers.split()
    max = num[0]
    min = num[0]
    for i in range(1, len(num)):
        if int(min) > int(num[i]):
            min = num[i]
        if int(max) < int(num[i]):
            max = num[i]
    return str(max) + ' ' + str(min)