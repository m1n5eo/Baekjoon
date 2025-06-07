import sys
input = sys.stdin.readline

dance = set()

for _ in range(int(input())):
    a, b = map(str, input().split())

    if a == 'ChongChong' or b == 'ChongChong':
        dance.add(a)
        dance.add(b)
    elif a in dance:
        dance.add(b)
    elif b in dance:
        dance.add(a)

print(len(list(dance)))