import sys
input = sys.stdin.readline

n, m = map(int, input().split())
word = [input()[:-1] for _ in range(n)]
note = dict()

for w in word:
    if len(w) >= m:
        if not w in note:
            note[w] = 1
        else:
            note[w] += 1

for n in sorted(note.items(), key = lambda x: (-x[1], -len(x[0]), x[0])):
    print(n[0])