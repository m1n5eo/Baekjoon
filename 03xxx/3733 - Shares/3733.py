while True:
    try:
        n, m = map(int, input().split())        
        print(m//(n+1))
    except EOFError:
        break