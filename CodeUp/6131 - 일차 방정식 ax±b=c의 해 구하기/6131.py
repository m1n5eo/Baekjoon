str = input()
sw = 0

for i in range(len(str)):
    if str[i] == '+':
        sw = 1
    elif str[i] == '-':
        sw = -1

str = str.replace('+', '=').replace('-', '=').split('=')
str[0] = str[0].rstrip('x')

res = (int(str[2])-int(str[1]))/int(str[0]) if sw == 1 else (int(str[2])+int(str[1]))/int(str[0])

print("{:.2f}".format(res))