def is_triangle(a, b, c):
    arr = [a, b, c]
    arr.sort()
    if arr[0]+arr[1] > arr[2]:
        return True
    else:
        return False