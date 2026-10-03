import sys
input = sys.stdin.readline

INF = 1234567890987654321

def solve():
    d, p, q = map(int, input().split())
    ret = INF
    if p < q: p, q = q, p
    for c in range(min(q, d//q)+2):
        if d-p*c <= 0: ret = min(ret, p*c)
        elif ((d-p*c)//q)*q < d-p*c: ret = min(ret, ((d-p*c)//q+1)*q + c*p)
        else: ret = min(ret, ((d-p*c)//q)*q + c*p)
    return ret

if __name__ == '__main__':
    print(solve())