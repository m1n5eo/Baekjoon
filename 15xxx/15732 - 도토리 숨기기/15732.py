import sys
input = sys.stdin.readline

n, k, d = map(int, input().split())
box = list()

for _ in range(k):
    a, b, c = map(int, input().split())
    box.append([a, b, c])

start = 1
end = n

while start <= end:
    mid = (start + end) // 2
    count = 0

    for i in range(k):
        if box[i][1] <= mid:
            count += (box[i][1] - box[i][0]) // box[i][2] + 1
        elif box[i][0] <= mid:
            count += (mid - box[i][0]) // box[i][2] + 1
    
    if count < d:
        start = mid+1
    else:
        end = mid-1

print(start)