import heapq
import sys
input = sys.stdin.readline

MOD = 1000000007

def solve():
    n = int(input())
    slime = list(map(int, input().split()))
    heap = []
    for s in slime: heapq.heappush(heap, s)
    ret = 1
    while len(heap) > 1:
        k = heapq.heappop(heap)
        k *= heapq.heappop(heap)
        heapq.heappush(heap, k)
        ret = (ret*k) % MOD
    return ret % MOD

if __name__ == '__main__':
    tc = int(input())
    for _ in range(tc): print(solve())