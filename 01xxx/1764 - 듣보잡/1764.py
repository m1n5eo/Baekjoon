import sys
input = sys.stdin.readline

n, m = map(int, input().split())
person = {input()[:-1] for _ in range(n)}
result = list()

for _ in range(m):
    name = input()[:-1]
    if name in person:
        result.append(name)

print(len(result))
for r in sorted(result):
    print(r)