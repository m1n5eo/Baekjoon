import sys
input = sys.stdin.readline

while True:
    triangle = sorted(list(map(int, input().split())))

    if triangle[2] == 0:
        break
    elif triangle[0] + triangle[1] <= triangle[2]:
        print("Invalid")
    elif triangle[0] == triangle[2]:
        print("Equilateral")
    elif triangle[0] == triangle[1] or triangle[1] == triangle[2]:
        print("Isosceles")
    else:
        print("Scalene")