#include <stdio.h>

int main() {
    int n, a, b, c;
    scanf("%d %1d%1d%1d", &n, &a, &b, &c);
    printf("%d\n%d\n%d\n%d", c*n, b*n, a*n, c*n+b*n*10+a*n*100);
}