import sys
input = sys.stdin.readline

n = int(input())
card = [0, 1]

for i in range(1, 20):
    for j in range(2, 2**i+1, 2):
        card.append(j)
        card[0] += 1

        if card[0] == n:
            break

print(card[n])