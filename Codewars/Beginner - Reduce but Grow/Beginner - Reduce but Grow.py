def grow(arr):
    ans = 1
    for i in range(len(arr)):
        ans = ans * arr[i]
    return ans