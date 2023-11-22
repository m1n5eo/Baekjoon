def find_average(nums):
    sum = 0
    for i in range(len(nums)):
        sum = sum+nums[i]
    return sum/len(nums)