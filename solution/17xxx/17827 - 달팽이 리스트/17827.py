import sys
input = sys.stdin.readline

n, m, v = map(int, input().split())
node = list(map(int, input().split()))
    
for _ in range(m):
    question = int(input())
    print(node[(question-(v-1))%(n-v+1)+(v-1)] if question > v else node[question])