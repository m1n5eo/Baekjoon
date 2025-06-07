import sys
input = sys.stdin.readline

deque = [0 for _ in range(2222222)]
left, right = 1000000, 999999

for _ in range(int(input())):
    cmd = list(map(int, input().split()))

    if cmd[0] == 1:
        left -= 1
        deque[left] = cmd[1]
    elif cmd[0] == 2:
        right += 1
        deque[right] = cmd[1]
    elif cmd[0] == 3:
        print(deque[left] if right - left + 1 else -1)
        left += (1 if right - left + 1 else 0)
    elif cmd[0] == 4:
        print(deque[right] if right - left + 1 else -1)
        right -= (1 if right - left + 1 else 0)
    elif cmd[0] == 5:
        print(right - left + 1)
    elif cmd[0] == 6:
        print(0 if right - left + 1 else 1)
    elif cmd[0] == 7:
        print(deque[left] if right - left + 1 else -1)
    elif cmd[0] == 8:
        print(deque[right] if right - left + 1 else -1)