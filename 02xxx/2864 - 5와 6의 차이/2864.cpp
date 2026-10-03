#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, minn = 0, maxx = 0, s = 1;
    scanf("%d %d", &n, &m);
    while(1) {
        if(n == 0 && m == 0) break;
        if(n%10 == 5 || n%10 == 6) {
            minn = minn + s*5;
            maxx = maxx + s*6;
        }
        else {
            minn = minn + s*(n%10);
            maxx = maxx + s*(n%10);
        }

        if(m%10 == 5 || m%10 == 6) {
            minn = minn + s*5;
            maxx = maxx + s*6;
        }
        else {
            minn = minn + s*(m%10);
            maxx = maxx + s*(m%10);
        }
        n=n/10;
        m=m/10;
        s=s*10;
    }
    printf("%d %d", minn, maxx);
}
