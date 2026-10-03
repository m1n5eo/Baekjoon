import sys
input = sys.stdin.readline

n, m = map(int, input().split())
pokemon = [input()[:-1] for _ in range(n)]

for _ in range(m):
    search = input()[:-1]
    print(pokemon[int(search) - 1] if '0' <= search[0] and search[0] <= '9' else pokemon.index(search) + 1)