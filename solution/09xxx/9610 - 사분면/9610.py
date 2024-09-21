res = list(0 for i in range(5))

n = int(input())

for _ in range(n):
    x, y = map(int, input().split())

    if x == 0 or y == 0:
        res[0] = res[0]+1
    elif x > 0 and y > 0:
        res[1] = res[1]+1
    elif x < 0 and y > 0:
        res[2] = res[2]+1
    elif x < 0 and y < 0:
        res[3] = res[3]+1
    elif x > 0 and y < 0:
        res[4] = res[4]+1

for i in range(1, 5):
    print("Q{}: {}".format(i, res[i]))
print("AXIS: {}".format(res[0]))