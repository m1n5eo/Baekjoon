import sys
input = sys.stdin.readline

n = int(input())
count = dict()

for card in list(map(int, input().split())):
    if card in count:
        count[card] += 1
    else:
        count[card] = 1

m = int(input())

for card in list(map(int, input().split())):
    print(count[card] if card in count else 0, end=" ")