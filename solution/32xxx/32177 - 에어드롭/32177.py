import sys
input = sys.stdin.readline

def find(parent, a):
    if a != parent[a]:
        parent[a] = find(parent, parent[a])

    return parent[a]

def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)

    if a > b:
        parent[a] = b
    else:
        parent[b] = a

n, k, t = map(int, input().split())

parent = []
for i in range(0, n+1):
    parent.append(i)

point = []
puang_x, puang_y, puang_version = map(int, input().split())
point.append([puang_x, puang_y, puang_version])

picture = []
for i in range(1, n+1):
    temp_x, temp_y, temp_version, temp_picture = map(int, input().split())
    point.append([temp_x, temp_y, temp_version])

    if temp_picture == 1:
        picture.append(i)

for i in range(0, n+1):
    for j in range(i+1, n+1):
        distance = (point[i][0]-point[j][0])*(point[i][0]-point[j][0]) + (point[i][1]-point[j][1])*(point[i][1]-point[j][1])

        if distance <= k*k and abs(point[i][2]-point[j][2]) <= t:
            union(parent, i, j)

check = False

for i in range(0, len(picture)):
    if(find(parent, parent[picture[i]]) == find(parent, 0)):
        print(picture[i], end=" ")
        check = True

if check == False:
    print(0)