#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;

    printf("a = %d, &a = %p\n", a, &a);
    printf("*p = %d, p = %p", *p, p);

    return 0;
}