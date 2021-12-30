w, h, b = map(float, input().split())
dap = w*h*b/8/1024/1024
print('%.2f MB'%dap)