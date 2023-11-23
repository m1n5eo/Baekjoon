def square_sum(numbers):
    sum = 0
    for i in range(len(numbers)):
        sum = sum + numbers[i]*numbers[i]
    return sum