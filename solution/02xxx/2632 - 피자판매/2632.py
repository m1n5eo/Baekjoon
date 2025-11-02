import sys
input = sys.stdin.readline

def solve():
    want = int(input())
    n = list(map(int, input().split()))
    pizza = [[int(input()) for _ in range(n[0])], [int(input()) for _ in range(n[1])]]
    prefix = [[pizza[0][0]], [pizza[1][0]]]
    for k in range(2):
        for i in range(1, n[k]):
            prefix[k].append(prefix[k][-1] + pizza[k][i])
    total = [prefix[0][-1], prefix[1][-1]]
    p = [[0, prefix[0][-1]], [0, prefix[1][-1]]]
    for k in range(2):
        for i in range(n[k]):
            for j in range(i+1, n[k]):
                p[k].append((prefix[k][i] - prefix[k][j]) % prefix[k][-1])
                p[k].append((prefix[k][j] - prefix[k][i]) % prefix[k][-1])
    p = [sorted(p[0]), sorted(p[1])]

    n = [len(p[0]), len(p[1])]
    d = [[[0, 1]], [[0, 1]]]
    for k in range(2):
        for i in range(1, n[k]):
            if p[k][i] != p[k][i-1]: d[k].append([p[k][i], 1])
            else: d[k][-1][1] += 1

    n = [len(d[0]), len(d[1])]
    ret = 0
    for i in range(n[0]):
        left, right = 0, n[1]-1
        find = want-d[0][i][0]
        while left < right:
            mid = (left+right)//2
            if d[1][left][0] == find:
                ret += d[0][i][1] * d[1][left][1]
                break
            elif d[1][mid][0] == find:
                ret += d[0][i][1] * d[1][mid][1]
                break
            elif d[1][right][0] == find:
                ret += d[0][i][1] * d[1][right][1]
                break
            if d[1][mid][0] < find: left = mid+1
            else: right = mid-1
    return ret

if __name__ == '__main__':
    print(solve())