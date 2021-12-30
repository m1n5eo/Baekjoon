#include <stdio.h>

int main()
{
    int n, m, u, t;
    scanf("%d %d %d", &n, &m, &u);
    if(m < n && m < u) {
        m = t;
        n = m;
        t = n;
    }
    else if(u < n && u < m) {
        u = t;
        n = u;
        t = n;
    }
    for(int i = n; i >= 1; i--) {
        if(n%i==0 && m%i==0 && u%i==0) {
            printf("%d", i);
            return 0;
        }
    }
}