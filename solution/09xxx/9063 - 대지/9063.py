point = [list(map(int, input().split())) for _ in range(int(input()))]
print((max(p[0] for p in point) - min(p[0] for p in point)) * (max(p[1] for p in point) - min(p[1] for p in point)))