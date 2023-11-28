def findSquares(x,y):
    ans = 0
    if x > y:
        temp = x
        x = y
        y = temp
    for i in range(x):
        ans = ans + (x-i)*(y-i)
    return ans