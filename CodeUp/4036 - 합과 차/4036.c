#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n%d", (m+n)/2, n - ((m+n)/2));
}