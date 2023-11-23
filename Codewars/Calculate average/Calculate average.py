def find_average(numbers):
    if not(len(numbers)):
        return 0
    sum = 0
    for i in range(len(numbers)):
        sum = sum + numbers[i]
    return sum/len(numbers)