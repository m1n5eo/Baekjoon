t = int(input())

for _ in range(t):
    max_school = "Inital"
    max_alcohol = 0
    
    n = int(input())

    for _ in range(n):
        school, alcohol = map(str, input().split())

        if max_alcohol < int(alcohol):
            max_school = school
            max_alcohol = int(alcohol)
    
    print(max_school)