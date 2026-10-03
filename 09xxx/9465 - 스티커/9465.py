import sys
input = sys.stdin.readline

t = int(input())

for testcase in range(t):
    n = int(input())
    cost = [list(map(int, input().split())) for _ in range(2)]

    result = 0

    if n == 1:
        print(max(cost[0][0], cost[1][0]))
        continue

    cost[0][1] += cost[1][0]
    cost[1][1] += cost[0][0]

    for j in range(2, n):
        for i in range(2):
            cost[i][j] = cost[i][j] + max(cost[1-i][j-1], cost[1-i][j-2])
            result = max(result, cost[i][j])
    
    print(result if n != 2 else max(cost[0][1], cost[1][1]))