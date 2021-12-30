#include <stdio.h>

int main() {
    int n, m, t;
    scanf("%d %d", &n, &m);
    if (n > m && n % m == 0) {
        t = n / m;
        printf("%d*%d=%d", m, t, n);
    }
    else if (n <= m && m % n == 0) {
        t = m / n;
        printf("%d*%d=%d", n, t, m);
    }
    else printf("none");
}