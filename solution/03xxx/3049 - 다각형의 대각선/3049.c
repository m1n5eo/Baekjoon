#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int cross = (n*(n-1)*(n-2)*(n-3)) / 24;
    printf("%d", cross);

    return 0;
}