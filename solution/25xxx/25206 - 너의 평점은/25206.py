import sys
input = sys.stdin.readline

count = 0
sum = 0

for _ in range(20):
    subject, credit, grade = map(str, input().split())
    count += (float(credit) if grade != 'P' else 0)

    if grade == 'A+':
        sum += float(credit) * 4.5
    elif grade == 'A0':
        sum += float(credit) * 4.0
    elif grade == 'B+':
        sum += float(credit) * 3.5
    elif grade == 'B0':
        sum += float(credit) * 3.0
    elif grade == 'C+':
        sum += float(credit) * 2.5
    elif grade == 'C0':
        sum += float(credit) * 2.0
    elif grade == 'D+':
        sum += float(credit) * 1.5
    elif grade == 'D0':
        sum += float(credit) * 1.0
    elif grade == 'F':
        sum += float(credit) * 0.0

print(sum/count)