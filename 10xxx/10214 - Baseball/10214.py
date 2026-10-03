t = int(input())

for _ in range(t):
    yonsei = 0
    korea = 0

    for _ in range(9):
        score1, score2 = map(int, input().split())

        yonsei = yonsei+score1
        korea = korea+score2
    
    if yonsei > korea:
        print("Yonsei")
    elif yonsei < korea:
        print("Korea")
    else:
        print("Draw")