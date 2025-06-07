import sys
input = sys.stdin.readline

n, k = map(int, input().split())
circle = [i+1 for i in range(n)]
result = list()

while circle:
    for _ in range(k - 1):
        circle.append(circle.pop(0))
    result.append(circle.pop(0))

print('<', end="")
for i in range(len(result) - 1):
    print(str(result[i]) + ', ', end="")
print(str(result[-1]) + '>', end="")