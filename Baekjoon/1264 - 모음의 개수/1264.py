import sys
input = sys.stdin.readline

while True:
    str = input()[:-1]
    cnt = 0

    if str == "#":
        break

    for word in str:
        if word == 'A' or word == 'E' or word == 'I' or word == 'O' or word == 'U':
            cnt += 1
        elif word == 'a' or word == 'e' or word == 'i' or word == 'o' or word == 'u':
            cnt += 1
    
    print(cnt)