import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    str = input()[:-1]

    if str == "Algorithm":
        print("204")
    elif str == "DataAnalysis":
        print("207")
    elif str == "ArtificialIntelligence":
        print("302")
    elif str == "CyberSecurity":
        print("B101")
    elif str == "Network":
        print("303")
    elif str == "Startup":
        print("501")
    elif str == "TestStrategy":
        print("105")