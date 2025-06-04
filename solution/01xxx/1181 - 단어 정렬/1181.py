import sys
input = sys.stdin.readline

n = int(input())
for word in sorted(list(set([input()[:-1] for _ in range(n)])), key = lambda x: (len(x), x)):
    print(word)