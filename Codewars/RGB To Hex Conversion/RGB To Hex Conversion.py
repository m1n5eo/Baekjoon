def rgb(r, g, b):
    r = r if r >= 0 else 0
    r = r if r < 256 else 255
    
    g = g if g >= 0 else 0
    g = g if g < 256 else 255
    
    b = b if b >= 0 else 0
    b = b if b < 256 else 255
    
    return format(r, 'X').zfill(2) + format(g, 'X').zfill(2) + format(b, 'X').zfill(2)