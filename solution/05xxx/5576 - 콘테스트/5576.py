import sys
input = sys.stdin.readline

team1 = []
team2 = []

for i in range(10):
    temp = int(input())
    team1.append(temp)
    
for i in range(10):
    temp = int(input())
    team2.append(temp)

team1.sort()
team2.sort()

print(team1[9]+team1[8]+team1[7], team2[9]+team2[8]+team2[7])