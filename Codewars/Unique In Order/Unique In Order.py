def unique_in_order(sequence):
    ans = []
    if len(sequence) != 0:
        ans.append(sequence[0])
    for i in range(1, len(sequence)):
        if sequence[i-1] != sequence[i]:
            ans.append(sequence[i])
    return ans