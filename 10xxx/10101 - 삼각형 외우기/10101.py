import sys
input = sys.stdin.readline

triangle = list(int(input()) for _ in range(3))

if triangle == [60, 60, 60]:
    print("Equilateral")
elif triangle[0] + triangle[1] + triangle[2] == 180:
    if triangle[0] == triangle[1] or triangle[1] == triangle[2] or triangle[2] == triangle[0]:
        print("Isosceles")
    else:
        print("Scalene")
else:
    print("Error")