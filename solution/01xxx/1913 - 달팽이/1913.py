n = int(input())
m = int(input())

arr = [[0 for _ in range(n)] for _ in range(n)]
cnt = n*n

i = 0
j = 0
sw = 0

while True:
    arr[i][j] = cnt
    if cnt == m:
        ii = i
        jj = j
    cnt = cnt-1
    if cnt == 0:
        break
    if sw == 0:
        if i+1 < n and arr[i+1][j] == 0:
            i = i+1
        elif i+1 == n or arr[i+1][j] != 0:
            j = j+1
            sw = 1
    elif sw == 1:
        if j+1 < n and arr[i][j+1] == 0:
            j = j+1
        elif j+1 == n or arr[i][j+1] != 0:
            i = i-1
            sw = 2
    elif sw == 2:
        if i-1 > -1 and arr[i-1][j] == 0:
            i = i-1
        elif i-1 == -1 or arr[i-1][j] != 0:
            j = j-1
            sw = 3
    elif sw == 3:
        if j-1 > -1 and arr[i][j-1] == 0:
            j = j-1
        elif j-1 == -1 or arr[i][j-1] != 0:
            i = i+1
            sw = 0

for x in range(n):
    for y in range(n):
        print(arr[x][y], end=" ")
    print("\n", end="")
print(str(ii+1)+" "+str(jj+1))