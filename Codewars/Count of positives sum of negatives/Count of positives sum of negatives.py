def count_positives_sum_negatives(arr):
    if not(len(arr)):
        return []
    sum = 0
    cnt = 0
    for i in range(len(arr)):
        if arr[i] > 0:
            cnt = cnt+1
        else:
            sum = sum+arr[i]
    return [cnt, sum]