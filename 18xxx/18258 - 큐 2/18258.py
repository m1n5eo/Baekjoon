import sys
input = sys.stdin.readline

queue = list()
left, right = 0, -1

for _ in range(int(input())):
    command = list(map(str, input().split()))

    if command[0] == 'push':
        queue.append(int(command[1]))
        right += 1
    elif command[0] == 'pop':
        print(queue[left] if right - left + 1 else -1)
        left += (1 if right - left + 1 else 0)
    elif command[0] == 'size':
        print(right - left + 1)
    elif command[0] == 'empty':
        print(0 if right - left + 1 else 1)
    elif command[0] == 'front':
        print(queue[left] if right - left + 1 else -1)
    elif command[0] == 'back':
        print(queue[right] if right - left + 1 else -1)