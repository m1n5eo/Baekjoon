import sys
input = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    a = list(map(str, input().split()))

    name = dict()
    for i in range(n):
        name[a[i]] = i
    
    m = int(input())
    graph = [list() for _ in range(n)]
    count = [0 for _ in range(n)]

    for _ in range(m):
        a, b = map(str, input().split())

        graph[name[b]].append(a)
        count[name[a]] += 1

    root = list()
    
    for s in name.keys():
        if count[name[s]] == 0:
            root.append(s)
        
    result = [list() for _ in range(n)]
    
    for s in root:
        queue = [s]

        while queue:
            x = queue.pop(0)
            
            for next in graph[name[x]]:
                if count[name[next]] == 0:
                    continue
                elif count[name[next]] == 1:
                    count[name[next]] -= 1
                    result[name[x]].append(next)
                    queue.append(next)
                else:
                    count[name[next]] -= 1

    print(len(root))
    for r in sorted(root):
        print(r, end=" ")
    print()

    for s in sorted(name.keys()):
        print(s, len(result[name[s]]), end=" ")
        for r in sorted(result[name[s]]):
            print(r, end=" ")
        print()