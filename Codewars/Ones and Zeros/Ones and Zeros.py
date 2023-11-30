def binary_array_to_number(arr):
    two = 1
    ans = 0
    for i in range(len(arr)-1, -1, -1):
        ans = ans + arr[i]*two
        two = two * 2
    return ans