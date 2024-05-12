#include <stdio.h>

int main() {
    int n;
    double k;

    int *p1 = &n;
    double *p2 = &k;

    printf("%p %p", p1, p2);
}