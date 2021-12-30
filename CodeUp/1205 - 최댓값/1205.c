#include <stdio.h>

int main() {
    double n, m, max = 0, wow = 1;
    scanf("%lf %lf", &n, &m);
    if(n + m > max) max = n + m;
    if (n - m > max) max = n - m;
    if (m - n > max) max = m - n;
    if (n * m > max) max = n * m;
    if (n / m > max) max = n / m;
    if (m / n > max) max = m / n;
    for(int i = 1; i <= n; i++) wow = wow * m;
    if (wow > max) max = wow;
    wow = 1;
    for (int i = 1; i <= m; i++) wow = wow * n;
    if (wow > max) max = wow;
    printf("%lf", max);
}