import sys
input = sys.stdin.readline

n = int(input())
h = [0] + list(map(int, input().split())) + [0]

result = (len(h)-2)*2

for i in range(len(h)):
    result += h[i]*2+abs(h[i]-h[i+1]) if i != len(h)-1 else h[i]*2

print(result)