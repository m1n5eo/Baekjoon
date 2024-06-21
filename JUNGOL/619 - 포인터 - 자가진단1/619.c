#include <stdio.h>

int main() {
    int n;
    int *p = &n;

    scanf("%d", &n);
    printf("%#p %d", p, *p);

    return 0;
}