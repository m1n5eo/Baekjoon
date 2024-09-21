import sys
input = sys.stdin.readline

MAX = 1111111

result = [-1]*MAX
cnt = [0]*MAX
st = []

n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    cnt[a[i]] += 1

for i in range(n):
    while len(st) != 0 and cnt[a[st[-1]]] < cnt[a[i]]:
        result[st[-1]] = a[i]
        st.pop()
    st.append(i)

for i in range(n):
    print(result[i], end=" ")