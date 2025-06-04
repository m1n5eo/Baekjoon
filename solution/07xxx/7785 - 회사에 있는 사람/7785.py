import sys
input = sys.stdin.readline

now = list()

for _ in range(int(input())):
    people, status = map(str, input().split())

    if status == 'enter':
        now.append(people)
    elif status == 'leave':
        now.remove(people)

for n in sorted(now, reverse=True):
    print(n)