import sys
input = sys.stdin.readline

def isExist(number):
    start = 0
    end = n-1

    while start <= end:
        mid = (start+end)//2

        if a[mid] == number:
            return True
        elif a[mid] < number:
            start = mid+1
        else:
            end = mid-1
    
    return False

if __name__ == '__main__':
    n = int(input())
    a = sorted(list(map(int, input().split())))
    m = int(input())
    b = list(map(int, input().split()))

    for num in b:
        print(1 if isExist(num) == True else 0)