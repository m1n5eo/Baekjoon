#include <stdio.h>

int main() {
    int n, m, t;
    scanf("%d %d", &n, &m);
    if(n > m) {
        t = n;
        n = m;
        m = t;
    }
    for(int i = n; i >= 1; i--) {
        if(n % i == 0 && m % i == 0) {
            printf("%d\n", i);
            break;
        }
    }
    int cnt = m;
    while((cnt % n != 0 && cnt % m != 0) || (cnt % n != 0 || cnt % m != 0)) {
        cnt = cnt + 1;
    }
    printf("%d", cnt);
}