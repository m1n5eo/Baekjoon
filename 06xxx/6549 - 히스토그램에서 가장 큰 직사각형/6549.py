import sys
input = sys.stdin.readline

def histogram(table):
    if len(table) == 1:
        return table[0]

    mid = len(table)//2
    left, right = mid-1, mid

    height = min(table[left], table[right])
    width = 2
    area = height * width

    while 0 < left or right < len(table)-1:
        now = 0

        if left == 0:
            right += 1
            now = table[right]
        elif right == len(table)-1:
            left -= 1
            now = table[left]
        elif table[left-1] > table[right+1]:
            left -= 1
            now = table[left]
        else:
            right += 1
            now = table[right]
        
        height = min(now, height)
        width += 1
        area = max(area, height*width)

    return max(histogram(table[:mid]), histogram(table[mid:]), area)

if __name__ == '__main__':
    while True:
        table = list(map(int, input().split()))[1:]

        if not table:
            break
        
        print(histogram(table))