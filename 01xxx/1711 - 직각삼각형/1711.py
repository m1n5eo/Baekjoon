import sys
input = sys.stdin.readline

def distance(p1, p2):
    return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1])

n = int(input())
point = list()

for _ in range(n):
    x, y = map(int, input().split())
    point.append([x, y])

count = 0

for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            dist = [distance(point[i], point[j]), distance(point[j], point[k]), distance(point[k], point[i])]
            if dist[0] + dist[1] == dist[2] or dist[1] + dist[2] == dist[0] or dist[2] + dist[0] == dist[1]:
                count += 1

print(count)